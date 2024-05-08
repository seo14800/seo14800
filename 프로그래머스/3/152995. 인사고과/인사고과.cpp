#include <vector>
#include <algorithm>

using namespace std;

inline bool compare( vector<int> emp1, vector<int> emp2 )
{
    return( (emp1[0] + emp1[1]) > (emp2[0] + emp2[1]) );
}

int solution(vector<vector<int>> scores) {
    int answer = 1;
    int wanhoScore = scores[0][0] + scores[0][1];
    int comp, bSize;
    vector<int> wanho = scores[0];
    
    sort( scores.begin() + 1, scores.end(), compare );
    for( int i = 1; i < scores.size(); i++ )
    {
        if( (wanho[0] < scores[i][0]) && (wanho[1] < scores[i][1]) )
        {
            return -1;
        }
        
        comp = scores[i][0] + scores[i][1];
        if( wanhoScore < comp )
        {
            answer++;
        }
        else
        {
            break;
        }
    }

    bSize = answer;
    for( int i = 2; i < bSize; i++ )
    {
        for( int j = 1; j < i; j++ )
        {
            if( (scores[i][0] < scores[j][0]) && (scores[i][1] < scores[j][1]) )
            {
                answer--;
                break;
            }
        }
    }

    return answer;
}