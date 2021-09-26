#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;

const int maxn = 1e5+10;

int n,m,k;
ll v[maxn];

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> n >> m >> k;

	for(int i = 0 ; i < n ; ++i)cin >> v[i];

	sort(v,v+n);

	for(int i = 1 ; i < n ; ++i)v[i] = v[i]+v[i-1];

	k--;

	int x = (m-1)*k;
	x += m;

	x = n-x;

	cout << v[n-1]-v[x-1] << "\n";

	return 0;
}