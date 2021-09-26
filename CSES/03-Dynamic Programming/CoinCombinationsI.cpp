#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e7+10;
const int MOD = 1e9+7;

int n,m;
int v[maxn],dp[maxn];

int solve(int x)
{
	if(dp[x] != -1)return dp[x];

	dp[x] = 0;

	for(int i = 1 ; i <= n ; ++i)
	{
		if(x-v[i] < 0)continue;
		dp[x] += solve(x-v[i]);
		if(dp[x] >= MOD)dp[x] -= MOD;
	}

	return dp[x];
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> n >> m;

	for(int i = 1 ; i <= n ; ++i)cin >> v[i];

	memset(dp,-1,sizeof(dp));

	dp[0] = 1;

	cout << solve(m) << "\n";

	return 0;
} 
