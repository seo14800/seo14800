#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> compMap;

    for(int i = 0; i < completion.size(); i++)
    {
        compMap[completion[i]]++;
    }

    for(int i = 0; i < participant.size(); i++)
    {
        if(compMap.find(participant[i]) == compMap.end())
        {
            answer = participant[i];
            break;
        }
        else
        {
            if(compMap[participant[i]] == 0)
            {
                answer = participant[i];
                break;
            }
            compMap[participant[i]]--;
        }
    }

    return answer;
}