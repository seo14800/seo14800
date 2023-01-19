#include <iostream>
#include <vector>
#include <algorithm>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int N;
int mapArea[25][25];

bool checkArea[25][25];

vector<int> count_Apart;

int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int y, int x, int& count)
{
	count++;
	checkArea[y][x] = true;
	
	for(int i = 0; i < 4; i++)
	{
		int nextY = y + dir[i][0];
		int nextX = x + dir[i][1];
		
		if( 0 <= nextX && nextX < N && 0 <= nextY && nextY < N)
		{
			if(mapArea[nextY][nextX] == 1 && !checkArea[nextY][nextX])
				dfs(nextY, nextX, count);
		}
	}
}

int main(int argc, char** argv) {
	int count = 0;
	
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			scanf("%1d", &mapArea[i][j]);
		}
	}
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(mapArea[i][j] == 1 && !checkArea[i][j])
			{
				count = 0;
				dfs(i, j, count);
				count_Apart.push_back(count);
			}
		}
	}
	
	sort(count_Apart.begin(), count_Apart.end());
	cout << count_Apart.size() << '\n';
	
	for(int i = 0; i < count_Apart.size(); i++)
	{
		cout << count_Apart[i] << '\n';
	}
	
	return 0;
}