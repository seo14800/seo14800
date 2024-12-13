#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int TimeConvert(const string &strTime)
{
    int time = 0;

    int mm = std::stoi(strTime.substr(0, strTime.find(':')));
    int ss = std::stoi(strTime.substr(strTime.find(':') + 1));

    time = (mm * 60) + ss;

    return time;
}

string TimeConvert(const int &iTime)
{
    string time;

    int mm = (iTime / 60);
    int ss = iTime - (mm * 60);

    time = (mm < 10 ? "0" : "") + to_string(mm) + ":" + (ss < 10 ? "0" : "") + to_string(ss);

    return time;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    enum eCmds {
        NEXT = 0,
        PREV
    };
    const int step = 10;
    int videoLen = TimeConvert(video_len);
    int posTime = TimeConvert(pos);
    int opStart = TimeConvert(op_start);
    int opEnd = TimeConvert(op_end);
    unordered_map<string,int> umCmds;

    umCmds["next"] = NEXT;
    umCmds["prev"] = PREV;

    for(auto cmd : commands)
    {
        if(posTime >= opStart && posTime < opEnd)
        {
            posTime = opEnd;
        }

        switch (umCmds[cmd])
        {
        case NEXT:
            posTime += step;
            posTime = (posTime > videoLen) ? videoLen : posTime;
            break;

        case PREV:
            posTime -= step;
            posTime = (posTime < 0) ? 0 : posTime;
            break;
        
        default:
            break;
        }
    }

    if(posTime >= opStart && posTime < opEnd)
    {
        posTime = opEnd;
    }

    answer = TimeConvert(posTime);

    return answer;
}