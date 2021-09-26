#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e2+10;

int n , m , p , q ,c;

int vis[maxn], v[maxn];

vector<int> grafo[maxn];

int dfs(int x)
{
	if(vis[x] != -1) return 0;

	vis[x] = 1;

	if(x == q)
	{
		v[q] = c;
		return 1;
	}
	for(int i = 0 ; i <(int)grafo[x].size() ; ++i)
	{
		int u = grafo[x][i];

		if(vis[u] != -1)continue;
		int temp = dfs(u);
		
		if(temp == 1)
		{
			v[x] = c;
			return 1;
		}
	}
	return 0;
}

int main()
{

	cin >> n >> m;

	for(int i = 1 ; i < n ; ++i)
	{
		int a, b;
		cin >> a >>b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	for(int i = 1 ; i <= m ; ++i)
	{
		cin >> p >> q >> c;

		memset(vis , -1 , sizeof(vis));

		dfs(p);
	}

	for(int i = 1 ; i <= n ; ++i)
	{
		cout << v[i] << " ";
	}
	cout << "\n";

	return 0 ;

}