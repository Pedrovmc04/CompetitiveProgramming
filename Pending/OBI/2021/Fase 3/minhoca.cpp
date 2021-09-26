#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back

typedef int64_t ll;
typedef pair<int,int> pii;

const int maxn = 5e4+5;
const int INF = 0x3f3f3f3f;

int n,m,sz1,sz2;
int dist[maxn];
vector<int> v1,v2;
vector<int> graph[maxn];
map<pii,bool> mapa;

void bfs(int x)
{
	queue<int> fila;
	dist[x] = 0;

	fila.push(x);

	while(!fila.empty())
	{
		int u = fila.front();
		fila.pop();

		for(int v : graph[u])
		{
			if(dist[v] > dist[u]+1)
			{
				dist[v] = dist[u]+1;
				fila.push(v);
			}
		}
	}
}

int32_t main()
{
    ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    cin >> n;

    for(int i = 1 ; i < n ; ++i)
    {
    	int a,b;
    	cin >> a >> b;
    	graph[a].pb(b);
    	graph[b].pb(a);
    }

    memset(dist,INF,sizeof(dist));

    bfs(1);

    for(int i = 1 ; i <= n ; ++i)m = max(m,dist[i]);
   	for(int i = 1 ; i <= n ; ++i)if(dist[i] == m)v1.pb(i);

   	memset(dist,INF,sizeof(dist));
   	m = 0;

   	bfs(v1[0]);

   	for(int i = 1 ; i <= n ; ++i)m = max(m,dist[i]);
   	for(int i = 1 ; i <= n ; ++i)if(dist[i] == m)v2.pb(i);

   	sz1 = (int)v1.size();
   	sz2 = (int)v2.size();

   	/*for(int i = 0 ; i < (int)v1.size() ; ++i)cout << v1[i] << " ";
   	cout << "\n";
   	for(int i = 0 ; i < (int)v2.size() ; ++i)cout << v2[i] << " ";
   	cout << "\n";*/

   	for(int i = 0 ; i < sz1 ; ++i)
   	{
   		for(int j = 0 ; j < sz2 ; ++j)
   		{
   			int x = v1[i];
   			int y = v2[j];

   			if(x == y)continue;
   			if(x > y)swap(x,y);
   			if(mapa.find({x,y}) != mapa.end())continue;
   			else mapa[{x,y}] = 1;
   		}
   	}



   	cout << m+1 << "\n";

   	cout << mapa.size() << "\n";

    return 0;
}
