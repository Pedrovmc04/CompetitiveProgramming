#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3+5;
const int INF = 0x3f3f3f3f;

int n,m;
int v[maxn],p[maxn];
int dp[maxn][102000];

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(NULL);

	cin >> n >> m;

	for(int i = 0 ; i < n ; ++i)cin >> v[i];
	for(int i = 0 ; i < n ; ++i)cin >> p[i];


	for(int i = 1 ; i <= n ; ++i)
	{
		for(int j = 0 ; j <= m ; ++j)
		{
			dp[i][j] = dp[i-1][j];

			if(j >= v[i-1])
			{
				dp[i][j] = max(dp[i][j],dp[i-1][j-v[i-1]]+p[i-1]);
			}
		}
	}

	cout << dp[n][m] << "\n";

	return 0;
}