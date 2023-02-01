#include <string>
#include <vector>
#include <queue>

using namespace std;

#define MAX_NUMBER  1000000

struct ansnode{
    int depth;
    int x;
};

int solution(int x, int y, int n) {
    int answer = 0;
    bool lookup[MAX_NUMBER + 1] = {0, };
    queue<ansnode> ansq;
    ansnode cur, cal;

    if( (y < 1 || y > MAX_NUMBER) )
    {
        return -1;
    }
    else if( n < 1 || n > y )
    {
        return -1;
    }

    if( x == y )
    {
        return 0;
    }

    cur.depth = 0;
    cur.x = x;
    ansq.push(cur);
    while( ansq.empty() == false )
    {
        cur = ansq.front();
        if( cur.x == y )
        {
            answer = cur.depth;
            break;
        }

        cal.depth = cur.depth + 1;
        
        cal.x = cur.x * 3;
        if( cal.x <= y && (lookup[cal.x] != true) )
        {
            ansq.push(cal);
            lookup[cal.x] = true;
        }

        cal.x = cur.x * 2;
        if( cal.x <= y && (lookup[cal.x] != true) )
        {
            ansq.push(cal);
            lookup[cal.x] = true;
        }

        cal.x = cur.x + n;
        if( cal.x <= y && (lookup[cal.x] != true) )
        {
            ansq.push(cal);
            lookup[cal.x] = true;
        }

        ansq.pop();
    }

    answer = (answer == 0) ? -1 : answer;
    return answer;
}