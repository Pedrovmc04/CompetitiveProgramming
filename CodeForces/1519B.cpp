#include <bits/stdc++.h>

using namespace std;

int t,n,m,k;
bool ans;

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> t;

	for(; t > 0 ; --t)
	{
		cin >> n >> m >> k;

		int x = (n*m)-1;

		if(x == k)
		{
			cout << "YES\n";
		}else
		{
			cout << "NO\n";
		}
	}

	return 0;
}