#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer = players;
    unordered_map<string, int> raceMap;

    for(int idx = 0; idx < players.size(); idx++)
    {
        raceMap[players[idx]] = idx;
    }

    for(auto call : callings)
    {
        int index = raceMap[call];
        raceMap[call]--;
        raceMap[answer[index - 1]]++;
        answer[index].swap(answer[index - 1]);
    }

    return answer;
}