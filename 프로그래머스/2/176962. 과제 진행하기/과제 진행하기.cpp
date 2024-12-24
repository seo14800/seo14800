#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;

class WorkNode
{
public:
    string name_;
    int playtime_;
    WorkNode(string name, int playtime) : name_(name), playtime_(playtime) {}
};


int TimeConvert(const string &strTime)
{
    int time = 0;

    int hh = std::stoi(strTime.substr(0, strTime.find(':')));
    int mm = std::stoi(strTime.substr(strTime.find(':') + 1));

    time = (hh * 60) + mm;

    return time;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    map<int, WorkNode> workMap; // key : 시작시간, WorkNode : 이름, 소요시간
    stack<WorkNode> delayStack; // 일시중지한 과목들
    enum { NAME = 0, START, PLAYTIME };

    // 시작시간, 소요시간 분단위로 환산, 시작시간을 key하여 map에 삽입
    for(auto it : plans)
    {
        int sTime = TimeConvert(it[START]);
        int playTime = stoi(it[PLAYTIME]);
        workMap.emplace(sTime, WorkNode(it[NAME], playTime));
    }

    // map은 정렬되므로 맨앞 요소를 빼내어 시작시간, 시작과목을 정함
    auto startNode = workMap.extract(workMap.begin());
    int curTime = startNode.key();
    WorkNode curWork = startNode.mapped();
    int tick = 0;
    while( !workMap.empty() || !delayStack.empty() )
    {
        curTime++;  // 현재시간
        tick++;     // 현재 과목을 진행한 시간
        if(workMap.find(curTime) != workMap.end())  // 진행중 다른 과목을 시작해야하는 경우
        {
            if(curWork.playtime_ - tick == 0)
            {
                answer.push_back(curWork.name_);    // 다른 과목 시작시간과 완료 시간이 겹치는 경우
            }
            else
            {
                curWork.playtime_ -= tick;          // 진행한 시간만큼 소요시간 차감 후 stack에 저장
                delayStack.push(curWork);
            }
            tick = 0;
            auto nextNode = workMap.extract(workMap.begin());
            curWork = nextNode.mapped();
        }
        else if(curWork.playtime_ == tick)          //  소요시간만큼 진행이 완료된 경우
        {
            answer.push_back(curWork.name_);
            if(!delayStack.empty())                 // 중지된 과목이 있는지 stack 확인
            {
                curWork = delayStack.top();         // 가장 최근에 중지한 과목 꺼내기(LIFO)
                delayStack.pop();
            }
            else if(!workMap.empty())               // 중지된 과목 없음, 다른 과목 확인
            {
                auto nextNode = workMap.extract(workMap.begin());
                curWork = nextNode.mapped();
                curTime = nextNode.key();       // 현재시간을 다음과목 시작시간으로 업데이트
            }
            tick = 0;
        }
    }

    answer.push_back(curWork.name_);
    return answer;
}