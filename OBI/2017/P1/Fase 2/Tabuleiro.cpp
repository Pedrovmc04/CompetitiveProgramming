#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e2+10;

int n ;
int v[2]; 
int m[maxn][maxn];

int main()
{
	cin >> n;

	for(int i = 1 ; i <= n ; ++i)
	{
		for(int j = 1 ; j <= n ; ++j)
		{
			cin >> m[i][j];
		}
	}

	for(int i = 2 ; i <= n ; ++i)
	{
		for(int j = 2 ; j <= n ; ++j)
		{
			v[0] = 0;
			v[1] = 0;

			v[m[i-1][j]]++;
			v[m[i][j-1]]++;
			v[m[i-1][j-1]]++;

			if(v[0] < v[1]) m[i][j] = 0;
			else m[i][j] = 1;
		}
	}

	cout << m[n][n] << "\n";



	return 0;
}