#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int prev = 0, cur = 1;

    if(n <= 1)
    {
        return 1;
    }

    for(int i = 2; i <= n + 1; i++)
    {
        int next = (prev + cur) % 1000000007;
        prev = cur;
        cur = next;
    }

    answer = cur;
    return answer;
}