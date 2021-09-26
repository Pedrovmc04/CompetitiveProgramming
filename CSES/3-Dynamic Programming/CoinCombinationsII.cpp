#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+10;
const int MOD = 1e9+7;

int n,m;
int v[105];
int dp[maxn];

int main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> n >> m;

	for(int i = 1 ; i <= n ; ++i)cin >> v[i];

	sort(v+1,v+n+1);

	dp[0] = 1;
	
	for(int i = 1 ; i <= n ; ++i)
	{
		for(int j = 0 ;  j <= m ; ++j)
		{
			if(j-v[i] >= 0)
			{
				dp[j] += dp[j-v[i]];
				if(dp[j] >= MOD)dp[j] -= MOD;
			}
		}
	}

	cout << dp[m] << "\n";

}