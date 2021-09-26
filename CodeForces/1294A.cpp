#include <bits/stdc++.h>

using namespace std;

long long int m,ans;
long long int v[4];

int main()
{
	cin >> m;

	for(int i = 1 ; i <= m ; ++i)
	{
		ans = 0;
		long long int n;
		cin >> v[0] >> v[1] >> v[2] >> n;

		sort(v,v+3);

		ans += v[2] - v[0];
		ans += v[2] - v[1];
		n -= ans;

		if(n < 0 || n%3 != 0)
		{
			cout << "NO\n";
		}else
		{
			cout << "YES\n";
		}
	}

	return 0;
}