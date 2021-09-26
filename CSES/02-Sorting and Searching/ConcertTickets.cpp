#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pb push_back

const int maxn = 2e5+10;

typedef pair<int,int> pii;

int n,m;
multiset<int> v; // Ticket

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> n >> m;

	for(int i = 0 ; i < n ; ++i)
	{
		int a;
		cin >> a;
		v.insert(a);
	}

	for(int i = 0 ; i < m ; ++i)
	{
		int a;
		cin >> a;
		auto it = v.upper_bound(a);

		if(it == v.begin())cout << "-1" << "\n";
		else cout << *(--it) << "\n" , v.erase(it);
	}

	return 0;
}