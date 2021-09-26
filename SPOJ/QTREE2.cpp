#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef pair<int,int> pii;
typedef int64_t ll;

const int maxn = 1e4+10;
const int M = 20;

ll n,t;
ll height[maxn],pai[maxn],dist[maxn];
ll anc[maxn][M];
vector<pii> graph[maxn];

void DFS(ll x)
{
	for(auto v : graph[x])
	{
		if(!height[v.F])
		{
			height[v.F] = height[x]+1;
			pai[v.F] = x;
			dist[v.F] = dist[x] + v.S;
			DFS(v.F);
		}
	}
}

void init()
{
	memset(anc,-1,sizeof(anc));
	memset(dist,0,sizeof(dist));
	memset(pai,0,sizeof(pai));
	memset(height,0,sizeof(height));

	pai[1] = 1;
	height[1] = 1;
	DFS(1);


	for(int i = 1 ; i < maxn ; ++i)anc[i][0] = pai[i];

	for(int j = 1 ; j < M ; ++j)
	{
		for(int i = 1 ; i < maxn ; ++i)
			anc[i][j] = anc[anc[i][j-1]][j-1];
	}
}

ll LCA(int u , int v)
{
	if(height[v] > height[u])swap(u,v);

	for(int i = M-1 ; i >= 0 ; --i)
	{
		if(height[u] - (1<<i) >= height[v])
			u = anc[u][i];
	}

	if(u == v)return u;

	for(int i = M-1 ; i >= 0 ; --i)
	{
		if(anc[u][i] != -1 && anc[u][i] != anc[v][i])
		{
			u = anc[u][i];
			v = anc[v][i];
		}
	}

	return anc[u][0];
}

int solve(int u,int v, int k , int lca)
{
	if(dist[u] - dist[lca] + 1 <= k)
	{
		int x = dist[u]+dist[v]-2*dist[lca]+1;
		k = x-k;
		swap(u,v);
	}

	k--;

	for(int i = M-1 ; i >= 0 ; --i)
	{
		if((1<<i) <= k)
		{
			u = anc[u][i];
			k -= (1<<i);
		}
	}

	return u;
}

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> t;

	while(true)
	{
		if(t == 0)break;
		cin >> n;

		for(int i = 1 ; i <= n ; ++i)graph[i].clear();

		for(int i = 1 ; i < n ; ++i)
		{
			int a,b,c;
			cin >> a >> b >> c;
			graph[a].push_back({b,c});
			graph[b].push_back({a,c});
		}

		init();

		string q;

		while(cin >> q)
		{

			if(q == "DONE")break;

			if(q == "DIST")
			{
				int a,b;
				cin >> a >> b;
				ll ans = dist[a]+dist[b] - 2*dist[LCA(a,b)];
				cout << ans << "\n";
			}else
			{
				int a,b,k;
				cin >> a >> b >> k;
				ll node = LCA(a,b);
				cout << solve(a,b,k,node) << "\n";
			}
		}

		--t;
	}

	return 0;
}