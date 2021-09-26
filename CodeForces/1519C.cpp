#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int maxn = 2e5+10;

int t,n,x;
int mark[maxn],aux[maxn];
vector<int> m[maxn],v;

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> t;

	for(;t > 0 ; --t)
	{
		cin >> n;

		v.clear();

		for(int i = 0 ; i < n ; ++i)
		{
			cin >> aux[i];
			if(mark[aux[i]])continue;

			mark[aux[i]]++;
			v.pb(aux[i]);

			m[aux[i]].clear();
		}

		for(int i = 0 ; i < n ; ++i)
		{
			int a;
			cin >> a;
			int y = m[aux[i]].size();
			
			if(y == 0)
			{
				m.[aux[i]].pb(a);
			}else
			{
				m[aux[i]].pb(a+m[aux[i]][y-1]);
			}
		}

		for(int i : v)x = max(x,m[i].size());

		for(int k = 1 ; k <= x ; ++i)
		{
			for(int i : v)
			{

			}
		}
	}

	return 0;
}