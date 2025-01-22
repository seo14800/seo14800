#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> tandems(n + 1, 0);
    tandems[0] = 1;

    for (int i = 1; i <= n; ++i) 
    {
        for (int j = 0; j < i; ++j) 
        {
            tandems[i] += tandems[j] * tandems[i - 1 - j];
        }
    }

    answer = tandems[n];
    return answer;
}