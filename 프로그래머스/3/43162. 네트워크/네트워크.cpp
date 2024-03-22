#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0, cur;
    vector<bool> checkedCom(computers.size(), false);
    queue<int> bfsq;

    for( int com = 0; com < n; com++ )
    {
        if( checkedCom[com] == true )
            continue;

        bfsq.push(com);
        checkedCom[com] = true;
        while( !bfsq.empty() )
        {
            cur = bfsq.front();
            bfsq.pop();

            for( int i = 0; i < n; i++ )
            {
                if( computers[cur][i] == 0 || checkedCom[i] == true )
                    continue;
                
                bfsq.push(i);
                checkedCom[i] = true;
            }
        }
        answer++;
    }

    return answer;
}