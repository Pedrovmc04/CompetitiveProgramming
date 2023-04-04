#include <bits/stdc++.h>

using namespace std;

const int maxn = 510;
const int INF = 0x3f3f3f3f;

int n,m;
int dist[maxn][maxn];

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	while(true)
	{
		cin >> n >> m;

		if(n == 0 && m == 0)break;

		memset(dist,INF,sizeof(dist));

		for(int i = 1 ; i <= m ; ++i)
		{
			int a,b,c;
			cin >> a >> b >> c;
			if(dist[b][a] != INF)
			{
				dist[b][a] = 0;
				dist[a][b] = 0;
				continue;
			}
			dist[a][b] = c;
		}

		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);


		int q;
		cin >> q;

		for(int i = 1 ; i <= q ; ++i)
		{
			int a,b;
			cin >> a >> b;

			if(dist[a][b] == INF)
			{
				cout << "Nao e possivel entregar a carta\n";
			}else
			{
				cout << dist[a][b] << "\n";
			}
		}
		cout << "\n";
	}



	return 0;
}