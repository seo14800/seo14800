#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> compdate;
    int date, remain, mod, distribute;

    compdate.reserve(progresses.size());

    for(int i = 0; i < progresses.size(); i++)
    {
        remain = 100 - progresses[i];
        mod = (remain % speeds[i] > 0) ? 1 : 0;
        date = remain / speeds[i] + mod;

        compdate.push_back(date);
    }

    date = 0;
    distribute = compdate.front();
    for(int d = 0; d < compdate.size(); d++)
    {
        if(distribute >= compdate[d])
        {
            date++;
            continue;
        }

        answer.push_back(date);
        distribute = compdate[d];
        date = 1;
    }
    answer.push_back(date);
    
    return answer;
}