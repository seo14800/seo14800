#include <string>
#include <vector>

#define MAX_LENGTH  500

using namespace std;

int LANDX, LANDY = 0;
bool checkField[MAX_LENGTH][MAX_LENGTH] = {false, };
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
bool measurements[MAX_LENGTH] = {false, };
int totalOil[MAX_LENGTH] = {0, };

void oil_dfs(int x, int y, vector<vector<int>>& land, int& maxOil)
{
    int i, nextX, nextY;
    static int oilAmount = 1;
    static int stackDepth = 0;

    checkField[y][x] = true;
    measurements[x] = true;
    stackDepth++;
    for(i = 0; i < 4; i++)
    {
        nextY = y + dir[i][0];
        nextX = x + dir[i][1];

        if( nextX >= 0 && nextY >= 0 && nextX < LANDX && nextY < LANDY )
        {
            if( land[nextY][nextX] == 1 && checkField[nextY][nextX] == false )
            {
                oilAmount++;
                oil_dfs(nextX, nextY, land, maxOil);
            }
        }
    }

    stackDepth--;
    if(stackDepth == 0)
    {
        for(i = 0; i < LANDX; i++)
        {
            if(measurements[i])
            {
                totalOil[i] += oilAmount;
                measurements[i] = false;
                maxOil = (maxOil < totalOil[i]) ? totalOil[i] : maxOil;
            }
        }
        oilAmount = 1;
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    int width, depth;

    LANDY = land.size();
    LANDX = land[0].size();
    for(depth = 0; depth < LANDY; depth++)
    {
        for(width = 0; width < LANDX; width++)
        {
            if( land[depth][width] == 1 && checkField[depth][width] == false )
            {
                oil_dfs(width, depth, land, answer);
            }
        }
    }
    return answer;
}