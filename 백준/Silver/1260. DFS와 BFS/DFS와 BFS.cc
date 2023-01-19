#include <iostream>
#include <queue>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int n, m, v;

int b_check[1001];
int d_check[1001];
int gr[1001][1001];


void bfs(int start)
{
	queue<int> q;
	
	q.push(start);
	b_check[start] = 1;
	
	while(!q.empty())
	{
		int y = q.front();
		cout << y << ' ';
		q.pop();
		
		for(int i = 0; i <= n; i++)
		{
			if(gr[y][i] == 0 || b_check[i] == 1)
				continue;
			
			q.push(i);
			b_check[i] = 1;
		}
	}
}

void dfs(int x)
{	
	d_check[x] = 1;
	cout << x << ' ';
	
	for(int i = 1; i <= n; i++)
	{
		if(d_check[i] == 1 || gr[x][i] == 0)
			continue;
		dfs(i);
	}
}

int main(int argc, char** argv) {
	// nodes, edges, start
	int c1, c2;
	
	cin >> n >> m >> v;
	
	for(int i = 0; i < m; i++)
	{
		cin >> c1 >> c2;
		
		gr[c1][c2] = 1;
		gr[c2][c1] = 1;
	}
	
	dfs(v);
	cout << '\n';
	bfs(v);
	
	return 0;
}