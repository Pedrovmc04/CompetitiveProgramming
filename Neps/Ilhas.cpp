#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef pair<int,int> pii;

const int maxn = 1e5+10;
const int INF = 0x3f3f3f3f;

int n,m,ans_min,ans_max;
int dist[maxn];
vector<pii> graph[maxn];

void BFS(int x)
{
	priority_queue<pii,vector<pii>,greater<pii>> fila;

	dist[x] = 0;
	fila.push({dist[x],x});

	while(!fila.empty())
	{
		int u = fila.top().S;
		fila.pop();

		for(pii v : graph[u])
		{
			if(dist[v.F] > dist[u]+v.S)
			{
				dist[v.F] = dist[u]+v.S;
				fila.push({dist[v.F],v.F});
			}
		}
	}
}

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> n >> m;

	for(int i = 1 ; i <= m ; ++i)
	{
		int a,b,c;
		cin >> a >> b >> c;
		graph[a].push_back({b,c});
		graph[b].push_back({a,c});
	}

	memset(dist,INF,sizeof(dist));

	int x;
	cin >> x;

	BFS(x);
	ans_min = INF;

	for(int i = 1 ; i <= n ; ++i)
	{
		if(x == i)continue;
		ans_max = max(ans_max,dist[i]);
		ans_min = min(ans_min,dist[i]);
	}

	cout << (ans_max-ans_min) << "\n";

	return 0;
}