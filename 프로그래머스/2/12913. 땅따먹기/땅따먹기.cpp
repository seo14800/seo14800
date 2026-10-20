#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int landLen = land[0].size();
    vector<vector<int>> dp(land);

    for(int i = 1; i < dp.size(); i++)
    {
        for(int j = 0; j < landLen; j++)
        {
            int cur = dp[i][j];
            for(int k = 0; k < landLen; k++)
            {
                if(k == j)
                {
                    continue;
                }
                int prev = dp[i - 1][k];
                int sum = cur + prev;
                dp[i][j] = dp[i][j] <= sum ? sum : dp[i][j];
                answer = answer < dp[i][j] ? dp[i][j] : answer;
            }
        }
    }

    return answer;
}