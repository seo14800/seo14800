#include <string>
#include <vector>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0, lastCost = 0, appleNum = 0;
    int box, boxCost;
    vector<int> scoreMap(k + 1, 0);

    for(int i = 0; i < score.size(); i++)
    {
        scoreMap[score[i]]++;
    }

    for(int i = k; i > 0; i--)
    {
        if( scoreMap[i] )
        {
            appleNum += scoreMap[i];
            lastCost = i;
        }

        if( appleNum >= m )
        {
            box = appleNum / m;
            appleNum -= box * m;
            answer += (m * i) * box;
        }
    }

    return answer;
}