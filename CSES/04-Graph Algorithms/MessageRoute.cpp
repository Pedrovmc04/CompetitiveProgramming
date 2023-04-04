#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5;
const int INF = 0x3f3f3f3f;

int n,m;
int dist[maxn],lastpass[maxn];
vector<int> graph[maxn],ans;

void bfs(int a)
{
	queue<int> fila;

	fila.push(a);

	while(!fila.empty())
	{
		int u = fila.front();
		fila.pop();

		for(int xx : graph[u])
		{
			if(dist[xx] > dist[u] + 1)
			{
				dist[xx] = dist[u] + 1;
				fila.push(xx);
				lastpass[xx] = u;
			}
		}
	}
}


int main()
{
	cin >> n >> m;

	for(int i = 1; i <= m ; ++i)
	{
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	memset(dist,INF,sizeof(dist));

	dist[1] = 0;

	bfs(1);

	if(dist[n] < INF)
	{
		cout << dist[n]+1 << "\n";

		ans.push_back(n);

		while(1 != n)
		{
			int p = lastpass[n];
			ans.push_back(p);
			n = lastpass[n];
		}

		reverse(ans.begin(),ans.end());

		for(int x : ans)
		{
			cout << x << " ";
		}
	}else
	{
		cout << "IMPOSSIBLE\n";
	}

	return 0;
}