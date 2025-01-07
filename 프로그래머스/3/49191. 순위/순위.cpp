#include <string>
#include <vector>

using namespace std;

int checkConnectedNodes(int start, vector<bool> &isVisited, const vector<vector<int>> &rankGraph)
{
    int visited = 0;
    vector<int> startNode = rankGraph[start];

    for(auto node : startNode)
    {
        if(isVisited[node] == false)
        {
            isVisited[node] = true;
            visited += checkConnectedNodes(node, isVisited, rankGraph) + 1;
        }
    }

    return visited;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    enum{ WINNER = 0, LOSER };
    vector<vector<int>> winRecord(n + 1);
    vector<vector<int>> loseRecord(n + 1);
    
    for(auto rt : results)
    {
        winRecord[rt[WINNER]].push_back(rt[LOSER]);
        loseRecord[rt[LOSER]].push_back(rt[WINNER]);
    }

    int loserNodes, winnerNodes;
    vector<bool> bVisited(n + 1);
    for(int i = 1; i <= n; i++)
    {
        fill_n(bVisited.begin(), bVisited.size(), false);
        loserNodes = checkConnectedNodes(i, bVisited, loseRecord);
        winnerNodes = checkConnectedNodes(i, bVisited, winRecord);
        
        if(loserNodes + winnerNodes == n - 1)
        {
            answer++;
        }
    }

    return answer;
}