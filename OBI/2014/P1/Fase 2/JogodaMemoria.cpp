#include <bits/stdc++.h>

#define ll int64_t

using namespace std;

const int maxn = 5e4+50;
const int M = 25;

ll n,ans;
ll height[maxn],pai[maxn],par[maxn],mark[maxn];
ll ancestral[maxn][M];
vector<int> graph[maxn];

void DFS(ll x)
{
	for(auto v : graph[x])
	{
		if(height[v] == -1)
		{
			height[v] = height[x]+1;
			pai[v] = x;
			DFS(v);
		}
	}
}

ll LCA(int u,int v)
{
	if(height[v] > height[u])swap(u,v);

	for(int i = M-1 ; i >= 0 ; --i)
		if(height[u] - (1<<i) >= height[v])u = ancestral[u][i];	

	if(u == v)return u;

	for(int i = M-1 ; i >= 0 ; --i)
	{
		if(ancestral[u][i] != -1 && ancestral[u][i] != ancestral[v][i])
		{
			u = ancestral[u][i];
			v = ancestral[v][i];
		}
	}

	return ancestral[u][0];
}

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(NULL);

	cin >> n;

	for(int i = 1 ; i <= n ; ++i) //Seta os pares
	{
		int k;
		cin >> k;

		if(mark[k] != 0)
		{
			par[i] = mark[k];
			par[mark[k]] = i;
		}

		mark[k] = i;
	}

	for(int i = 1 ; i < n ; ++i) //Monta o grafo
	{
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for(int i = 1 ; i < maxn ; ++i) //Seta tudo como -1
	{
		pai[i] = height[i] = -1;

		for(int j = 0 ; j < M ; ++j)
			ancestral[i][j] = -1;
	}

	pai[1] = 1;
	height[1] = 0;
	DFS(1);

	for(int i = 1 ; i <= n ; ++i)ancestral[i][0] = pai[i]; //Seto os ancestrais que estão em cima como os pais

	for(int j = 1; j<M; j++)//Seto os ancestrais na potencia de 2
        for(int i = 1; i<=n; i++)
            ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];

    for(int i = 1 ; i <= n ; ++i)
    	ans += height[i] + height[par[i]] - 2 * height[LCA(i,par[i])];

    cout << ans/2 << "\n";

	return 0;
}