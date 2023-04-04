#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back

typedef int64_t ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;

const int maxn = 2e5+10;

int n;
int dist[maxn];
vector<int> graph[maxn];

int dfs(int u)
{
	for(int v : graph[u])dist[u] += dfs(v)+1;

	return dist[u];
}

int32_t main()
{
    ios::sync_with_stdio(false),cin.tie(NULL);
   
    cin >> n;

    for(int i = 2 ; i <= n ; ++i)
    {
    	int x;
    	cin >> x;
    	graph[x].pb(i);
    }

    dist[1] = dfs(1);

    for(int i = 1 ; i <= n ; ++i)cout << dist[i] << " ";
   	cout << "\n";

    return 0;
}		