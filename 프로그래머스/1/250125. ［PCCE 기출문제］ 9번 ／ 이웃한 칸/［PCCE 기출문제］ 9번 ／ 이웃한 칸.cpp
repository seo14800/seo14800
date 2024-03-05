#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    string mycolor = board[h][w];
    int up, down, left, right;

    up = h - 1;
    down = h + 1;
    left = w - 1;
    right = w + 1;

    if( up >= 0 )
    {
        answer += (board[up][w] == mycolor) ? 1 : 0;
    }

    if( down < board.size() )
    {
        answer += (board[down][w] == mycolor) ? 1 : 0;
    }

    if( left >= 0 )
    {
        answer += (board[h][left] == mycolor) ? 1 : 0;
    }

    if( right < board.size() )
    {
        answer += (board[h][right] == mycolor) ? 1 : 0;
    }

    return answer;
}