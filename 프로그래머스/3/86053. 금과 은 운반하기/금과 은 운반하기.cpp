#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool canDeliverInTime(long long time, int a, int b, vector<int>& g, vector<int>& s, vector<int>& w, vector<int>& t)
{
    long long totalGold = 0;
    long long totalSilver = 0;
    long long totalCombined = 0;
    
    for (int i = 0; i < g.size(); ++i)
    {
        long long maxTrips = time / (2 * t[i]);
        if (time % (2 * t[i]) >= t[i])
        {
            ++maxTrips;
        }
        long long maxWeight = maxTrips * w[i];
        long long gold = min(static_cast<long long>(g[i]), maxWeight);
        long long silver = min(static_cast<long long>(s[i]), maxWeight);
        totalGold += gold;
        totalSilver += silver;
        totalCombined += min(static_cast<long long>(g[i] + s[i]), maxWeight);
    }
    
    return totalGold >= a && totalSilver >= b && totalCombined >= (a + b);
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t)
{
    long long left = 0;
    long long right = 4e14; // 충분히 큰 값으로 설정합니다.
    long long answer = right;
    
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        if (canDeliverInTime(mid, a, b, g, s, w, t))
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    
    return answer;
}