#include <iostream>
#include <queue>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int comNum;
int pairNum;
int comGraph[101][101];

bool bfs_check[101];

int bfs(int start)
{
	queue<int> q;
	int count = 0;
	
	q.push(start);
	bfs_check[start] = true;
	
	while(!q.empty())
	{
		int y = q.front();
		q.pop();
		
		for(int i = 1; i <= comNum; i++)
		{
			if(bfs_check[i] || !comGraph[y][i])
				continue;
			
			q.push(i);
			bfs_check[i] = true;
			count++;
		}
	}
	
	return count;
}

int main(int argc, char** argv) {
	int c1, c2;
	
	cin >> comNum;
	cin >> pairNum;
	
	for(int i = 0; i < pairNum; i++)
	{
		cin >> c1 >> c2;
		
		comGraph[c1][c2] = c2;
		comGraph[c2][c1] = c1;
	}
	
	cout << bfs(1) << '\n';
	
	return 0;
}