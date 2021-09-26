#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+10;
const long long int MOD = 1000000007;

int n;
long long int dp[maxn];

int solve(int x)
{
	if(x > n)return 0;

	if(dp[x] != -1)return dp[x];

	if(x == n)return 1;

	long long int y = 0;

	for(int i = 1 ; i <= 6 ; ++i)
	{
		y += solve(x+i)%MOD;
		y = y%MOD;
	}

	return dp[x] = y;
}

int main()
{
	cin >> n;

	memset(dp,-1,sizeof(dp));

	cout << solve(0) << "\n";

	return 0;
}