#include <string>
#include <vector>
#include <queue>

using namespace std;

bool trySeesaw(int &p1, int &p2)
{
    int dist1, dist2;
    for( dist1 = 2; dist1 <= 4; dist1++ )
    {
        for( dist2 = 2; dist2 <= 4; dist2++ )
        {
            if( (p1 * dist1) == (p2 * dist2) )
            {
                return true;
            }
        }
    }
    return false;
}

long long solution(vector<int> weights) {
    long long answer = 0;
    long long count;
    long long countMap[1024] = {0, };
    vector<queue<long long>> weightMap(1024);
    int w1, w2;

    for( w1 = 0; w1 < weights.size(); w1++ )
    {
        if( countMap[weights[w1]] > 0 )
        {
            count = countMap[weights[w1]] - weightMap[weights[w1]].front();
            weightMap[weights[w1]].pop();
            answer += count;
            continue;
        }

        count = 0;
        for(w2 = w1 + 1; w2 < weights.size(); w2++)
        {
            if( trySeesaw(weights[w1], weights[w2]) )
            {
                count++;
                if( (weights[w1] == weights[w2]) )
                {
                    weightMap[weights[w1]].push(count);
                }
            }
        }
        answer += count;
        countMap[weights[w1]] = count;
    }

    return answer;
}