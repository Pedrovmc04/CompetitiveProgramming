#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;

const int maxn = 1e5+10;

ll n,m,ans;
ll v[maxn];
set<int> num;

int bb(int u)
{
	int ini=1,fim=n,meio;

	while(ini <= fim)
	{
		meio = (ini+fim)>>1;

		cout << v[meio] << " | " << meio << "\n";

		if(v[meio] == u)
		{
			cout << "achei\n";
			return meio;
		}else if(v[meio] < u)
		{
			ini = meio+1;
		}else if(v[meio] > u)
		{
			fim = meio-1;
		}
	}
	return 0;
}

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> n >> m;

	for(int i = 1 ; i <= n ; ++i)
	{
		cin >> v[i];
		num.insert(v[i]);
	}

	sort(v+1,v+n+1);

	for(int i = 1 ; i <= n ; ++i)cout << v[i] << " ";

	cout << "\n";

	for(int i = 1 ; i <= n ; ++i)
	{
		for(int j = i+1 ; j <= n ; ++j)
		{
			int x = m/(v[i]*v[j]);
			if(x<v[j])continue;
			if(x == v[j] && x == v[j+1])
			{
				ans++;
				continue;
			}

			if(num.find(x) != num.end())
		}
	}

	cout << ans << "\n";

	return 0;
}