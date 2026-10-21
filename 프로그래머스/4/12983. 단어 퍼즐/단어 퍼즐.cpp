#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(vector<string> strs, string t)
{
    const int INF = 1e9;
    int n = t.size();
    vector<int> dp(n + 1, INF);
    dp[0] = 0;   // 아무것도 안 만든 상태는 조각 0개

    for (int i = 0; i < n; i++)
    {
        if (dp[i] == INF)
        {
            continue;   // i 위치까지 만들 방법이 없으면 여기서 출발 불가
        }

        for (int j = 0; j < strs.size(); j++)
        {
            int len = strs[j].size();
            if (i + len > n)
            {
                continue;
            }
            if (t.compare(i, len, strs[j]) == 0)
            {
                // break 하지 않고 맞는 조각을 전부 반영
                dp[i + len] = min(dp[i + len], dp[i] + 1);
            }
        }
    }

    return dp[n] == INF ? -1 : dp[n];
}