#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define MAX_NUM 1000000

bool isPrime(int n)
{
    if (n <= 1)
        return false; // 1 이하는 소수가 아님

    if (n == 2)
        return true;  // 2는 유일한 짝수 소수

    if (n % 2 == 0)
        return false; // 2 외의 짝수는 소수가 아님

    int sqrtN = std::sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2)
    {
        if (n % i == 0)
            return false; // 나누어 떨어지는 경우 소수가 아님
    }
    return true;
}

int solution(int n) {
    int answer = 0;
    
    for( int i = 1; i <= n; i++ )
    {
        if( isPrime(i) )
            answer++;
    }
    
    return answer;
}