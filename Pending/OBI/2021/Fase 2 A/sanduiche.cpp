#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int maxn = 20;

bool flag = true;
int n,m,ans;
int mark[maxn];
vector<int> v[maxn];

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> n >> m;

	for(int i = 0 ; i < m ; ++i)
	{
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		v[a].pb(b);
		v[b].pb(a);
	}

	for(int mask = 1 ; mask <= (1<<n)-1 ; ++mask)
	{
		flag = true;
		for(int i = 0 ; i < n ; ++i)
		{
			if(mark[i] && (mask & (1<<i)))
			{
				flag = false;
				break;
			}

			if(mask & (1<<i))
			{
				mark[i] = 1;
				for(int u : v[i])
				{
					mark[u] = 1;
				}
			}
		}
		memset(mark,0,sizeof(mark));
		if(flag)ans++;
	}

	cout << ans << "\n";

	return 0;
}