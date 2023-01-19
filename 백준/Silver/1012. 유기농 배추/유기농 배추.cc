#include <iostream>
#include <queue>
#include <vector>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MAX_SIZE	50
#define MAX_CABBAGE	2500

using namespace std;

int t, m, n, k;
vector<int> cnt_worm;

int cabbageField[MAX_SIZE][MAX_SIZE];
bool checkField[MAX_SIZE][MAX_SIZE];

int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int y, int x)
{
	checkField[y][x] = true;
	
	for(int i = 0; i < 4; i++)
	{
		int nextY = y + dir[i][0];
		int nextX = x + dir[i][1];
		
		if( 0 <= nextX && nextX < m && 0 <= nextY && nextY < n)					// 최대크기 내부인지 check 
		{	
			if(cabbageField[nextY][nextX] == 1 && !checkField[nextY][nextX])	// 새로운 양배추 발견  
				dfs(nextY, nextX);
		}
	}
}

void init()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cabbageField[i][j] = 0;
			checkField[i][j] = false;
		}
	}
}

int main(int argc, char** argv) {
	int x, y;
	int worm = 0;

	cin >> t;
	// test case 수 만큼 loop 
	for(int i = 0; i < t; i++)
	{
		init();		// 배추밭 배열, 방문 check 배열 초기화 
		worm = 0;
		
		//	m = 가로(x), n = 세로(y), k = 배추 개수  
		cin >> m >> n >> k;
		
		for(int j = 0; j < k; j++)
		{
			// 배추 위치 0 <= x <= m - 1, 0 <= y <= n - 1 
			cin >> x >> y;
			cabbageField[y][x] = 1;
		}
		
		// 세로 길이 
		for(int hori = 0; hori < n; hori++)
		{
			// 가로 길이 
			for(int ver = 0; ver < m; ver++)
			{
				if(cabbageField[hori][ver] == 1 && !checkField[hori][ver])
				{
					// 배추 구역마다 지렁이 추가 
					dfs(hori, ver);
					worm++;
				}
			}
		}
		
		cnt_worm.push_back(worm); 
	}
	
	for(int i = 0; i < cnt_worm.size(); i++)
	{
		cout << cnt_worm[i] << '\n';
	}
	
	return 0;
}