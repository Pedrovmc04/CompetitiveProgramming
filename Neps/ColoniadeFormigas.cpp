#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef int64_t ll;
typedef pair<int,int> pii;

const int maxn = 1e5+10;
const int M = 20;

ll n,q,height[maxn],pai[maxn];
ll anc[maxn][M],ans[maxn][M];
vector<pii> graph[maxn];

void DFS(ll x)
{
	for(auto v : graph[x])
	{
		if(!height[v.F])
		{
			height[v.F] = height[x]+1;
			pai[v.F] = x;
			ans[v.F][0] = v.S;
			DFS(v.F);
		}
	}
}

ll LCA(int u,int v)
{
	if(height[v] > height[u])swap(u,v);

	ll resp = 0;

	for(int i = M-1 ; i >= 0 ; --i)
		if(height[u] - (1<<i) >= height[v])
			resp += ans[u][i],u = anc[u][i];

	if(u == v)return resp;

	for(int i = M-1 ; i >= 0 ; --i)
	{
		if(anc[u][i] != -1 && anc[u][i] != anc[v][i])
		{
			resp += ans[u][i]+ans[v][i];
			u = anc[u][i];
			v = anc[v][i];
		}
	}

	return resp+ans[u][0]+ans[v][0];
}

void init()
{

	memset(anc, -1, sizeof anc);
    memset(height, 0, sizeof height);
    memset(pai, 0, sizeof pai);

    height[0] = 1;
    DFS(0);

    for(int i = 1 ; i <= n ; ++i)anc[i][0] = pai[i]; //define ancestral de cima

    for(int j = 1 ; j < M ; ++j) // define ancestral das potencias de 2
		{
			for(int i = 0 ; i <= n ; ++i)
			{
				anc[i][j] = anc[anc[i][j-1]][j-1];
				ans[i][j] = ans[anc[i][j-1]][j-1] + ans[i][j-1];
			}
		}

}

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(NULL);

	while(true)
	{
		cin >> n;
		if(n == 0)break;

		for(int i = 0 ; i <= n ; ++i)graph[i].clear();

		for(int i = 1 ; i < n ; ++i)
		{
			ll a,b;
			cin >> a >> b;
			graph[i].push_back({a,b});
			graph[a].push_back({i,b});
		}

		init();

		cin >> q;

		for(int i = 1 ; i <= q ; ++i)
		{
			int a,b;
			cin >> a >> b;

			cout << (ll)LCA(a,b) << " ";
		}

		cout << "\n";
	}

	return 0;
}