#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int a;

vector<int> v;

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	for(int i = 1 ; i <= 3 ; ++i)
	{
		cin >> a;
		v.pb(a);
	}

	sort(v.begin(),v.end());

	cout << v[1] << "\n";

	return 0;
}