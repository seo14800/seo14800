#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MIN_NUM = 1;
const int MAX_NUM = 1000000;

long long solution(int k, int d) {
    long long answer = 0;
    long long a;
    long long x, y, z;


    try
    {
        if( (k < MIN_NUM || k > MAX_NUM) || (d < MIN_NUM || d > MAX_NUM) )
        {
            throw answer;
        }
    }
    catch(const std::exception& e)
    {
        cout << "out of range" << endl;
        std::cerr << e.what() << '\n';
    }

// solve1 - fail
    a = 0;
    while( true )
    {
        x = a * k;
        if( x > d )
        {
            break;
        }

        z = ((long)d * d) - (x * x);
        y = sqrt(z)/k;
        answer += y + 1;

        a++;
    }

    return answer;
}