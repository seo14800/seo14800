#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string numStr = "0123456789";
    
    for( int i = 1; i < food.size(); i++ )
    {
        if( food[i] < 2 )
            continue;
        
        for( int fn = 0; fn < (food[i] / 2); fn++ )
        {
            answer += numStr[i];
        }
    }
    
    answer += numStr[0];
    for( int i = answer.size() - 2; i >= 0; i-- )
    {
        answer += answer[i];
    }
    return answer;
}