#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer(4, -1);

    for( int i = 0; i < wallpaper.size(); i++ )
    {
        for( int j = 0; j < wallpaper[i].size(); j++ )
        {
            if( wallpaper[i][j] == '#' )
            {
                if( answer[0] == -1 )
                {
                    answer[0] = i;
                    answer[1] = j;
                    answer[2] = i;
                    answer[3] = j;
                }
                else
                {
                    answer[1] = (answer[1] > j) ? j : answer[1];
                    answer[2] = i;
                    answer[3] = (answer[3] < j) ? j : answer[3];
                }
            }
        }
    }

    answer[2]++;
    answer[3]++;

    return answer;
}