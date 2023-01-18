#include <string>
#include <vector>

using namespace std;

#define MAX_SIZE_CATEGORY   10000000
#define MAX_MANDARIN_NUM    100000

int gCategory[MAX_SIZE_CATEGORY + 1] = {0, };
int gCountPool[MAX_SIZE_CATEGORY + 1] = {0, };

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int add = 0, sum = 0, count = 0;
    int index;
    int tIdx, dIdx;
    
    vector<int> division;

    for( tIdx = 0; tIdx < tangerine.size(); tIdx++ )
    {
        index = tangerine[tIdx];
        gCategory[index]++;

        if( gCategory[index] == 1 )
        {
            division.push_back(tangerine[tIdx]);
        }
        else if( gCategory[index] == k )
        {
            return 1;
        }
    }
    
    for( dIdx = 0; dIdx < division.size(); dIdx++ )
    {
        index = division[dIdx];
        gCountPool[gCategory[index]]++;
    }

    for( dIdx = MAX_SIZE_CATEGORY; dIdx > 0; dIdx-- )
    {
        switch (gCountPool[dIdx])
        {
        case 0: break;
        default:
            add = dIdx;
            count = gCountPool[dIdx];
            break;
        }

        while(count > 0)
        {
            sum += add;
            answer++;
            count--;
            if( sum >= k )
            {
                return answer;
            }
        }
    }
    
    return answer;
}

int main()
{
    return 0;
}