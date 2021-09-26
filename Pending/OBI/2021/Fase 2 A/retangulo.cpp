#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int n,a,b,c,d;
int v[maxn];

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> n;

	for(int i = 1 ; i <= n ; ++i)
	{
		cin >> v[i];
		v[i] += v[i-1];
	}

	int x = v[n/2-1];
	int y = v[n-1];

	a = x;
	b = v[n/2]-x;
	c = y-v[n/2];
	d = v[n]-y;

	cout << a << " " << b << " " << c << " " << d << "\n";

	return 0;
}