#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    long long sum[2] = {0, 0};
    int pulse[2] = {1, -1}, mpoint[2] = {0, 0};
    long long max[2] = {sequence[0] * pulse[0], sequence[0] * pulse[1]};

    for( int i = 0; i < sequence.size(); i++ )
    {
        for( int p = 0; p < 2; p++ )
        {
            sum[p] += sequence[i] * pulse[p];
            if(sum[p] > max[p])
            {
                max[p] = sum[p];
                mpoint[p] = i;
            }
            pulse[p] = pulse[p] * -1;
        }
    }

    pulse[0] = 1;
    pulse[1] = -1;
    for( int p = 0; p < 2; p++ )
    {
        sum[0] = 0;
        for( int i = 0; i <= mpoint[p]; i++ )
        {
            sum[0] += sequence[i] * pulse[p];
            sum[1] = max[p] - sum[0];
            if( max[p] < sum[1] )
            {
                max[p] = sum[1];
                sum[0] = 0;
            }
            pulse[p] = pulse[p] * -1;
        }
    }

    answer = (max[0] > max[1]) ? max[0] : max[1];

    return answer;
}