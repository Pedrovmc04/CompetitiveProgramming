#include <bits/stdc++.h>

using namespace std;

int dx[] = {1,-1,0,0,1,-1,1,-1};
int dy[] = {0,0,1,-1,1,-1,-1,1};

int n = 15 , ans;
int v[10];
int m[20][20] ;

void dfs(int x , int y, int z)
{
	v[z] = 1;
	int a = 1 ;
	while(m[x+a][y] == z)
	{
		v[z]++;
		a++;
	}
	a = 1;
	while(m[x-a][y] == z)
	{
		v[z]++;
		a++;
	}
	a = 1;

	if(v[z] >= 5) ans = z;

	v[z] = 1;


	while(m[x][y+a] == z)
	{
		v[z]++;
		a++;
	}
	a = 1;
	while(m[x][y-a] == z)
	{
		v[z]++;
		a++;
	}
	a = 1;

	if(v[z] >= 5) ans = z;

	v[z] = 1;

	while(m[x+a][y+a] == z)
	{
		v[z]++;
		a++;
	}
	a = 1;
	while(m[x-a][y-a] == z)
	{
		v[z]++;
		a++;
	}
	a = 1;
	if(v[z] >= 5) ans = z;
	
	v[z] = 1;

	while(m[x-a][y+a] == z)
	{
		v[z]++;
		a++;
	}
	a = 1;
	while(m[x+a][y-a] == z)
	{
		v[z]++;
		a++;
	}
	a = 1;
	if(v[z] >= 5) ans = z;
}

int main()
{
	for(int i = 1 ; i <= n ; ++i)
	{
		for(int j = 1 ; j <= n ; ++j)
		{
			cin >> m[i][j];
		}
	}

	for(int i = 1 ; i <= n ; ++i)
	{
		for(int j = 1 ; j <= n ; ++j)
		{
			if(m[i][j] == 1) dfs(i,j,1);
			else if(m[i][j] == 2) dfs(i,j,2);
		}
	}


	cout << ans << "\n";


	return 0;
}
