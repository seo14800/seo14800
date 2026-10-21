#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    vector<vector<bool>> ispud(n + 1, vector<bool>(m + 1, false));
    for(int i = 0; i < puddles.size(); i++)
    {
        int pm = puddles[i][0], pn = puddles[i][1];
        ispud[pn][pm] = true;
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[1][1] = 1;
    vector<int> prev(2, 1);
    int cn = 1, cm = 1;
    for(cn = 1; cn <= n; cn++)
    {
        for(cm = 1; cm <= m; cm++)
        {
            if(ispud[cn][cm])
            {
                dp[cn][cm] = 0;
                continue;
            }
            int prevn = cn - 1, prevm = cm - 1;
            dp[cn][cm] += (dp[prevn][cm] + dp[cn][prevm]) % 1000000007;
        }
    }

    answer = dp[n][m];
    return answer;
}