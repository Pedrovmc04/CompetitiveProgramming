#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

long long n,ans=1;

int main()
{

	cin >> n;

	for(int i = 1 ; i <= n ; ++i)
	{
		ans = (ans*2)%MOD;
	}

	cout << ans << "\n";

	return 0;
}