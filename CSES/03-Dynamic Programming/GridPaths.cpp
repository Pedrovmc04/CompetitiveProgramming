#include <bits/stdc++.h>

#define int int64_t

using namespace std;

const int maxn = 1e3+10;
const int MOD = 1e9+7;

int dx[] = {1,0};
int dy[] = {0,1};

int n;
int dp[maxn][maxn];
char matrix[maxn][maxn];

int solve(int x, int y)
{
	if(matrix[x][y] == '*')return 0;
	if(dp[x][y] != -1)return dp[x][y];

	dp[x][y] = 0;

	for(int i = 0 ; i < 2 ; ++i)
	{
		int xx = x+dx[i];
		int yy = y+dy[i];
		if(xx > n || yy > n)continue;
		dp[x][y] += solve(xx,yy);
		if(dp[x][y] >= MOD)dp[x][y] -= MOD;
	}

	return dp[x][y];
}

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> n;

	memset(dp,-1,sizeof(dp));

	for(int i = 1 ; i <= n ; ++i)
	{
		for(int j = 1 ; j <= n ; ++j)
		{
			cin >> matrix[i][j];
		}
	}

	dp[n][n] = 1;

	cout << solve(1,1) << "\n";
}