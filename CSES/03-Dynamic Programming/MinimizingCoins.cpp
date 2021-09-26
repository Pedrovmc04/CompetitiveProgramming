#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e6+10;

int n,m,ans;
int v[110],dp[maxn],mark[maxn];

int solve(int k)
{
	if(k < 0)return INF;
	if(dp[k] < INF || mark[k])return dp[k];

	mark[k] = 1;

	for(int i = 0 ; i < n ; ++i)
	{
		dp[k] = min(dp[k],solve(k-v[i]) + 1);
	}

	return dp[k];
}

int main()
{
	cin >> n >> m;

	for(int i = 0; i < n ; ++i)
	{
		cin >> v[i];
	}

	sort(v,v+n);
	memset(dp,INF,sizeof(dp));
	dp[0] = 0;

	ans = solve(m);

	if(ans == INF)
	{
		cout << "-1\n";
	}else
	{
		cout << ans << "\n";
	}

	return 0;
}