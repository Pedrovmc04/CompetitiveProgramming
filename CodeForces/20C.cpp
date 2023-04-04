#include <bits/stdc++.h>

#define int int64_t
#define F first
#define S second

using namespace std;

const int maxn = 2e5+50;
const int INF = 1e18;

typedef pair<int,int> pii;

int n,q;
int dist[maxn],pai[maxn];
vector<int> ans;
vector<pii> graph[maxn];

void BFS(int x)
{
	priority_queue<pii,vector<pii>, greater<pii>> fila;

	dist[x] = 0;
	pai[x] = 0;
	fila.push({dist[x],x});

	while(!fila.empty())
	{
		int u = fila.top().S;
		fila.pop();

		for(auto v : graph[u])
		{
			if(dist[v.F] > dist[u]+v.S)
			{
				dist[v.F] = dist[u]+v.S;
				fila.push({dist[v.F],v.F});
				pai[v.F] = u;
			}
		}
	}

}

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	cin >> n >> q;

	for(int i = 1 ; i <= q ; ++i)
	{
		int a,b,c;
		cin >> a >> b >> c;
		graph[a].push_back({b,c});
		graph[b].push_back({a,c});
	}

	for(int i = 1 ; i <= n ; i++) dist[i] = INF ; 

	BFS(1);

	if(dist[n] == INF)
	{
		cout << "-1\n"; 
	}else
	{
		int y = n;
		while(y != 0)
		{
			ans.push_back(y);
			y = pai[y];
		}
		
		reverse(ans.begin(), ans.end());

		for(int c : ans)cout << c << " ";

		cout << "\n";
	}
	return 0;
}