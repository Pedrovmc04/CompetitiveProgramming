#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e3+5;
const int INF = 0x3f3f3f3f;

int n,m;
int mat[maxn][maxn],dp[maxn][maxn][3];

int solve(int x , int y , int dir)
{
	if(x <= 0 || y <= 0 || x > n || y > m)return -INF;
	if(x == n && y == m)return mat[x][y];
	if(dp[x][y][dir] != -1)return dp[x][y][dir];

	if(dir == 0)return dp[x][y][dir] = max(solve(x,y+1,0),solve(x+1,y,2)) + mat[x][y];

	if(dir == 1)return dp[x][y][dir] = max(solve(x,y-1,1),solve(x+1,y,2)) + mat[x][y];

	return dp[x][y][dir] = max({solve(x,y+1,0),solve(x,y-1,1),solve(x+1,y,2)}) + mat[x][y];
}

int main()
{
	cin >> n >> m;

	for(int i = 1 ; i <= n ; ++i)
	{
		for(int j = 1 ; j <= m ; ++j)
		{
			cin >> mat[i][j];
		}
	}

	memset(dp,-1,sizeof(dp));

	cout << max(solve(1,1,0),solve(1,1,2)) << "\n";


	return 0; 
}