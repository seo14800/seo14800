#include <string>
#include <vector>

using namespace std;

#define LEFT    0
#define RIGHT   1

string solution(vector<int> numbers, string hand) {
    string answer = "";
    string fingerMap = "LR";
    vector<vector<int>> numMap = {  {3,1}, {0,0}, {0,1},
                                    {0,2}, {1,0}, {1,1},
                                    {1,2}, {2,0}, {2,1},
                                    {2,2}, {3,0}, {3,2} };
    int lastLoc[2] = {10, 11};
    int distance[2] = {0, 0};
    int mainHand = RIGHT, x, y, choice;

    if( hand == "left" )
        mainHand = LEFT;

    for( auto it:numbers )
    {
        switch (it)
        {
        case 1:
        case 4:
        case 7:
            answer += fingerMap[LEFT];
            lastLoc[LEFT] = it;
            break;
        
        case 3:
        case 6:
        case 9:
            answer += fingerMap[RIGHT];
            lastLoc[RIGHT] = it;
            break;
        
        default:
            x = abs(numMap[it][0] - numMap[lastLoc[LEFT]][0]);
            y = abs(numMap[it][1] - numMap[lastLoc[LEFT]][1]);
            if( y < 0 )
                y = y * -1;
            distance[LEFT] = x + y;

            x = abs(numMap[it][0] - numMap[lastLoc[RIGHT]][0]);
            y = abs(numMap[it][1] - numMap[lastLoc[RIGHT]][1]);
            distance[RIGHT] = x + y; 

            if( distance[RIGHT] > distance[LEFT] )
                choice = LEFT;
            else if( distance[RIGHT] < distance[LEFT] )
                choice = RIGHT;
            else
                choice = mainHand;

            answer += fingerMap[choice];
            lastLoc[choice] = it;
            break;
        }
    }
    return answer;
}