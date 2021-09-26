#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+5;
const int INF = 0x3f3f3f3f;

int n;
int dp[maxn];

int solve(int x)
{
	if(dp[x] != INF)return dp[x];

	int u = x;

	while(u > 0)
	{
		int y = u%10;
		u = u/10;
		if(y == 0)continue;
		dp[x] = min(dp[x],solve(x-y)+1);
	}

	return dp[x];
}

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	memset(dp,INF,sizeof(dp));

	dp[0] = 1;

	cin >> n;

	cout << solve(n)-1 << "\n";

	return 0;
}