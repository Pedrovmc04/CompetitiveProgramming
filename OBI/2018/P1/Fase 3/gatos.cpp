#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;

const int maxn = 5e2+10;

int dx[] = {0,0,1,2,1,1,2,2,0,0,1,1,2,2,-1,-2,-1,-2,-1,-2,-1,-1,-2,-2}; //Posições possiveis para o gato pular
int dy[] = {1,2,0,0,1,2,1,2,-1,-2,-1,-2,-1,-2,0,0,1,1,2,2,-1,-2,-1,-2};

int l , c , contador = 1; // largura , coluna , contador ;
int mark[maxn][maxn] ,m[maxn][maxn] ,dist[maxn][maxn]; //marcador , matrix , distancia ;

void bfs(int x , int y)
{
	queue<pair<int,int>> fila; //fila
	queue<pair<int,int>> row;  //axuliar da fila

	fila.push({x, y});

////////////////////////////////////////////////////////////////////////////
	while(true)
	{
		while(!fila.empty())
		{
			int a , b;
			a = fila.front().F;
			b = fila.front().S;
			fila.pop();

			for(int i = 0 ; i < 24 ; ++i)
			{	
				int xx = a + dx[i];
				int yy = b + dy[i];

				if(m[xx][yy] == 1 and dist[xx][yy] == -1)
				{
					dist[xx][yy] = contador ;

					row.push({xx,yy});
				}
			}
		}

		if(row.empty() == 1) break;
		else contador++;
////////////////////////////////////////////////////////////////////////
		while(!row.empty())
		{
			int a, b;

			a = row.front().F;
			b = row.front().S;

			row.pop();

			for(int i = 0 ; i < 24 ; ++i)
			{	
				int xx = a + dx[i];
				int yy = b + dy[i];

				if(m[xx][yy] == 1 and dist[xx][yy] == -1)
				{
					dist[xx][yy] = contador ;

					fila.push({xx,yy});
				}
			}
		}

		if(fila.empty() == 1) break;
		else contador++;
	}
////////////////////////////////////////////////////////////////////////
}

int main(){

	cin >> l >> c;

	for(int i = 1 ; i <= l ; ++i)
	{
		for(int j = 1 ; j <= c ; ++j)
		{
			cin >> m[i][j];
			if(m[i][j] == 1) dist[i][j] = -1;
		}
	}

	dist[1][1] = 0;

	bfs(1,1);

	cout << dist[l][c] << "\n";
 
	return 0;
}