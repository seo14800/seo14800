#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> yearnMap;

    for(int idx = 0; idx < name.size(); idx++)
    {
        yearnMap[name[idx]] = yearning[idx];
    }

    for(auto it : photo)
    {
        int yearnScore = 0;
        for(auto who : it)
        {
            yearnScore += yearnMap[who];
        }
        answer.push_back(yearnScore);
    }
    return answer;
}