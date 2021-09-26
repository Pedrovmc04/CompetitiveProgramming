#include <bits/stdc++.h>

#define int int64_t

using namespace std;

const int maxn = 1e5;
const int MOD = 1e9+7;

int n,m,ans;
int v[maxn];
int dp[maxn][120];

int solve(int pos, int val)
{
	if(pos > n)return 1;
	if(dp[pos][val] != -1)return dp[pos][val];
	if(v[pos] != 0)return dp[pos][val] = solve(pos+1,val);

	dp[pos][val] = 0;

	for(int i = val-1 ; i <= val+1; ++i)
	{
		if(i >= 0 && i <= m)
		{
			dp[pos][val] += solve(pos+1,i);
			if(dp[pos][val] >= MOD)dp[pos][val] = dp[pos][val] - MOD;
		} 
	}
	return dp[pos][val];
}

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1 ; i <= n ; ++i)cin >> v[i];

	memset(dp,-1,sizeof(dp));

	if(v[1] == 0)
	{
		for(int i = 1 ; i <= m ; ++i)
		{
			ans += solve(1,i);
			if(ans >= MOD)ans = ans - MOD;
		}
	}else
	{
		ans += solve(1,v[1]);
	}

	cout << ans << "\n";

	return 0;
}