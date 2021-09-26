#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+10;

long long int n,q;
long long int v[maxn];

int main()
{
	cin >> n >> q;

	for(int i = 1 ; i <= n ; ++i)
	{
		cin >> v[i];
		v[i] += v[i-1];
	}

	for(int i = 1 ; i <= q ; ++i)
	{
		int a,b;
		cin >> a >> b;

		cout << v[b]-v[a-1] << "\n";

	}

	return 0;
}