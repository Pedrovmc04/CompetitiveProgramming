#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
string step = "DURL";

const int maxn = 1e3+10;
const int INF = 0x3f3f3f3f;

int n,m;
pair<int,int> ini,fim;
int matrix[maxn][maxn],dist[maxn][maxn],lastpass[maxn][maxn];
//string caminho[maxn][maxn];

void bfs(int a , int b)
{
	queue<pair<int,int>> fila;

	fila.push({a,b});

	while(!fila.empty())
	{
		int x = fila.front().F;
		int y = fila.front().S;
		fila.pop();

		for(int i = 0 ; i < 4 ; ++i)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if(matrix[xx][yy] == 1 || xx > n || xx < 1 || y > m || y < 1)continue;

			if(dist[xx][yy] > dist[x][y] + 1)
			{
				dist[xx][yy] = dist[x][y]+1;
				fila.push({xx,yy});
				lastpass[xx][yy] = i;
			}

		}
	}
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	cin >> n >> m;

	for(int i = 1; i <= n ; ++i)
	{
		for(int j = 1 ; j <= m ; ++j)
		{
			char x;
			cin >> x;

			if(x == '#')matrix[i][j] = 1;
			else if(x == 'A')
			{
				matrix[i][j] = 2;
				ini.F = i;
				ini.S = j;
			}else if(x == 'B')
			{
				matrix[i][j] = 3;
				fim.F = i;
				fim.S = j;
			}
		}
	}

	memset(dist,INF,sizeof(dist));
	dist[ini.F][ini.S] = 0;

	bfs(ini.F,ini.S);

	vector<char> teste;

	if(dist[fim.F][fim.S] < INF)
	{
		cout << "YES\n";
		cout << dist[fim.F][fim.S] << "\n";

		vector<int> aux;

		while(fim != ini)
		{
			int p = lastpass[fim.F][fim.S];
			aux.push_back(p);
			fim.F = fim.F - dx[p];
			fim.S = fim.S - dy[p];
		}

		reverse(aux.begin(), aux.end());

		for(auto c : aux)
		{
			cout << step[c];
		}
		cout << "\n";


	}else{
		cout << "NO\n";
	}

	return 0;
}