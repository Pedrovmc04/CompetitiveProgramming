#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int MOD = 998244353;
const int maxn = 1e6;

int n,ans;


int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	ans = (1LL << 60);
	cin >> n;

	for (int i = 0; i <= 60; i++)
	{
		int a = n / (1LL << i);
		int b = i;
		int c = n - a * (1LL << i);
		ans = min(ans, a + b + c);
	}

	cout << ans << "\n";

	return 0;
}