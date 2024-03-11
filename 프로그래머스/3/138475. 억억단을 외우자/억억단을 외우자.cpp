#include <string>
#include <vector>

using namespace std;

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer(starts.size());
    vector<int> div(e + 1), searched(e + 1);
    int maxDivisiors = 0;
    int divisors, s, prevs, minStart;

    for( auto it : starts )
        minStart = min(minStart, it);

    for( int i = 1; i <= e; i++ )
    {
        for( int j = 1; j <= e; j++ )
        {
            if( i * j > e )
            {
                break;
            }
            div[i * j]++;
        }
    }

    for( s = e; s >= minStart; s-- )
    {
        divisors = div[s];
        if( divisors >= maxDivisiors )
        {
            maxDivisiors = divisors;
            searched[s] = s;
            prevs = s;
        }
        else
        {
            searched[s] = searched[prevs];
        }
    }

    for( s = 0; s < starts.size(); s++ )
        answer[s] = searched[starts[s]];

    return answer;
}