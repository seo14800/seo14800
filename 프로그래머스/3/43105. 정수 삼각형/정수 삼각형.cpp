#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> dp(triangle);
    for(int i = 1; i < dp.size(); i++)
    {
        dp[i][0] += dp[i - 1][0];
        dp[i][i] += dp[i - 1][i - 1];

        for(int j = 1; j < i; j++)
        {
            int prev = i - 1;
            dp[i][j] += dp[prev][j] > dp[prev][j - 1] ? dp[prev][j] : dp[prev][j - 1];
            answer = answer < dp[i][j] ? dp[i][j] : answer;
        }
    }
    return answer;
}