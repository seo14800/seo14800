#include <string>
#include <vector>
#include <deque>
#include <map>

#define LEFT    0
#define RIGHT   1
#define ROTATE      1
#define SHIFTROW    2

using namespace std;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    static map<string, int> operMap;
    deque<int> dqCol[2];
    deque<deque<int>> dqRow(rc.size());
    int height = rc.size() - 1;
    int right = rc[0].size() - 1;
    int topIdx = 0, botIdx = height;

    for(auto it : rc)
    {
        dqCol[LEFT].push_back(it.front());
        dqCol[RIGHT].push_back(it.back());
        for( int i = 1; i < right; i++ )
        {
            dqRow[topIdx].push_back(it[i]);
        }
        topIdx++;
    }

    topIdx = 0;
    operMap["Rotate"] = ROTATE;
    operMap["ShiftRow"] = SHIFTROW;
    for( auto it : operations )
    {
        switch ( operMap[it] )
        {
        case ROTATE:
            dqRow[topIdx].push_front(dqCol[LEFT][0]);
            dqCol[LEFT].pop_front();

            dqCol[RIGHT].push_front(dqRow[topIdx].back());
            dqRow[topIdx].pop_back();

            dqRow[botIdx].push_back(dqCol[RIGHT].back());
            dqCol[RIGHT].pop_back();

            dqCol[LEFT].push_back(dqRow[botIdx].front());
            dqRow[botIdx].pop_front();
            break;

        case SHIFTROW:
            dqCol[LEFT].push_front(dqCol[LEFT].back());
            dqCol[LEFT].pop_back();
            dqCol[RIGHT].push_front(dqCol[RIGHT].back());
            dqCol[RIGHT].pop_back();
            topIdx--;
            botIdx--;
            break;

        default:
            break;
        }

        if( topIdx < 0 )
        {
            topIdx = height;
        }

        if( botIdx < 0 )
        {
            botIdx = height;
        }
        
    }

    for( int i = 0; i <= height; i++ )
    {
        rc[i][0] = dqCol[LEFT][i];
        rc[i][right] = dqCol[RIGHT][i];
        for( int j = 1; j < right; j++ )
        {
            rc[i][j] = dqRow[topIdx][j - 1];
        }
        topIdx++;
        if( topIdx > height )
        {
            topIdx = 0;
        }
    }

    return rc;
}