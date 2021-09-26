#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

int n,m,ans;
int mark[maxn][maxn];
char matrix[maxn][maxn];

void dfs(int x,int y)
{
	if(mark[x][y])return;

	mark[x][y] = 1;

	for(int i = 0 ; i < 4 ; ++i)
	{
		int xx = x+dx[i];
		int yy = y+dy[i];

		if(matrix[xx][yy] == '.')dfs(xx,yy);
	}
}

int main()
{
	cin >> n >> m;

	for(int i = 1; i <= n ; ++i)
	{
		for(int j = 1 ; j <= m ;++j)
		{
			cin >> matrix[i][j];
		}
	}

	for(int i = 1; i <= n ; ++i)
	{
		for(int j = 1 ; j <= m ;++j)
		{
			if(matrix[i][j] == '.' && !mark[i][j])
			{
				ans++;
				dfs(i,j);
			}
		}
	}

	cout << ans << "\n";

	return 0;
}