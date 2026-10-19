#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    const long long MOD = 1000000007;

    if (n % 2 == 1)
    {
        return 0;
    }

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    long long sum = 0;   // dp[0] + dp[2] + ... + dp[i - 4]

    for (int i = 2; i <= n; i += 2)
    {
        dp[i] = (3 * dp[i - 2] + 2 * sum) % MOD;
        sum = (sum + dp[i - 2]) % MOD;
    }

    return dp[n];
}