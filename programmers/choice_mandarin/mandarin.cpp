#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

#define MAX_SIZE_CATEGORY   10000000 
#define MAX_MANDARIN_NUM    100000

int gCategory[MAX_SIZE_CATEGORY] = {0, };

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int index;
    int tIdx, dIdx;
    vector<int> division;

    memset(gCategory, 0, sizeof(gCategory));
    for( tIdx = 0; tIdx < tangerine.size(); tIdx++ )
    {
        index = tangerine[tIdx] - 1;
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
        index = division[dIdx] - 1;
        cout << "gCategory[" << index << "] : " << gCategory[index] << endl;
    }

    return answer;
}

int main()
{
    cout << "mandarin" << endl;
    return 0;
}