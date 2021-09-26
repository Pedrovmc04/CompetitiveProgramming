#include <bits/stdc++.h>

using namespace std;

const int maxn = 22;
const int MOD = 1e9+7;

int n,m;
int matrix[maxn][maxn],dp[maxn][1<<21];

int solve(int k, int mask)
{
	if(dp[k][mask] != -1)return dp[k][mask];
	if(k>=n)return 0;

	dp[k][mask] = 0;

	for(int i = 0 ; i < n ; ++i)
	{
		if(!matrix[k][i] || mask & (1<<i))continue;

		dp[k][mask] += solve(i,mask|(1<<i));
		if(dp[k][mask] >= MOD)dp[k][mask] -= MOD;
	}

	return dp[k][mask];
}

int main()
{
	ios::sync_with_stdio(false),cin.tie();

	cin >> n >> m;

	for(int i = 1 ; i <= m ; ++i)
	{
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		matrix[a][b] = 1;
		matrix[b][a] = 1;
	}

	memset(dp,-1,sizeof(dp));

	dp[n-1][(1<<n)-1] = 1;

	cout << solve(0,1) << "\n";

	return 0;
}