#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef pair<int,int> pii;
typedef pair<int,pii> pip;

const int maxn = 1e4+10 , inf = 1e9+7;

int n , x , y;
int dist[maxn];

vector<pii> grafo[maxn];

void bfs(int x)
{
	for(int i = 1 ; i <= n ; ++i)
	{
		dist[i] = inf;
	}

	priority_queue<pii , vector<pii> , greater<pii>> fila;

	fila.push({0,x});
	dist[x] = 0;

	while(!fila.empty())
	{
		int u = fila.top().S;
		fila.pop();

		for(int i = 0 ; i < (int)grafo[u].size() ; ++i)
		{
			int v = grafo[u][i].S , w = grafo[u][i].F;

			if(dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				fila.push({dist[v],v});
			}
		}
	}
}

int main()
{

	cin >> n >> x >> y;

	for(int i = 1 ; i < n ; ++i)
	{
		int a , b ,c;
		cin >> a >> b >> c;

		grafo[a].push_back({c,b});
		grafo[b].push_back({c,a});
	}

	bfs(x);

	cout << dist[y] << "\n";

	return 0;
}