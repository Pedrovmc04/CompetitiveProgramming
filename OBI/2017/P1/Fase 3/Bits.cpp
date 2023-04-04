#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3+10 , mod = 1e9+7;

int n , k , ans;

int dp[maxn][maxn];

int sla(int p , int c )
{
	if(dp[p][c] >= 0) return dp[p][c];

	if(p == n+1) return dp[p][c] = 1;

	
	int resp_0 = sla(p+1, 0);
	int resp_1 = 0;
	if(c < k) resp_1 += sla(p+1, c+1);

	return dp[p][c] = (resp_0 + resp_1)%mod;
}

int main()
{
	cin >> n >> k;
	--k;

	memset(dp , -1 , sizeof(dp));

	ans += sla(1, 0);

	cout << ans << "\n";


	return 0;
}