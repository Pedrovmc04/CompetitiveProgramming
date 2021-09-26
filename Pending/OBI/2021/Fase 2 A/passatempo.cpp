#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int maxn = 2e2+20;

int n,m,solve,sz;
int l[maxn],ans[maxn];
vector<int> v[maxn];
set<int> t[maxn];
map<string,int> mapa;

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> n >> m;

	for(int i = 1 ; i <= n ; ++i)
	{
		for(int j = 1 ; j <= m+1; ++j)
		{
			if(j == m+1){
				cin >> l[i];
				continue;
			}

			string x;
			cin >> x;
			if(mapa.find(x) == mapa.end())mapa[x] = ++sz;
			v[n+j].pb(mapa[x]);
			t[n+j].insert(mapa[x]);
			t[i].insert(mapa[x]);
			v[i].pb(mapa[x]);
		}
	}

	for(int i = 1 ; i <= m ; ++i)cin >> l[n+i];

	/*for(int i = 1 ; i <= n+m ; ++i)
	{
		for(int j : v[i])
		{
			cout << j << " ";
		}
		cout << "||" << l[i] << "\n";
	}*/

	memset(ans,-1,sizeof(ans));

	while(solve != sz)
	{
		for(int i = 1 ; i <= n+m ; ++i)
		{
			//cout << t[i].size() << "\n";
			if(t[i].size() != 1)continue;

			int x = l[i], y = 0 , z = 0;

			for(int j : v[i])
			{
				if(ans[j] != -1)x -= ans[j];
				else
				{
					y++;
					z = j;
				}
			}
			ans[z] = x/y;
			for(int i = 1 ; i <= n+m ; ++i)t[i].erase(z);
			solve++;
		}
	}

	map<string, int>::iterator it;

	for(it=mapa.begin(); it!=mapa.end(); it++){ 
		
		cout << (*it).first << " " << ans[(*it).second] << "\n";
	}

	return 0;
}