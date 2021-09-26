#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int n , t , soma;
int m[maxn][3];

int main()
{
	cin >> n >> t;

	for(int i = 1 ; i <= 2 ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			cin >> m[j][i];
		}
	}

	for(int i = 1 ; i <= t ; ++i)
	{
		int a ,b;
		cin >> a >> b;
		m[a][3] += 1;
		m[b+1][3] += -1;
	}

	for(int i = 1 ; i <= n ; ++i)
	{
		soma += m[i][3];
		if(soma % 2 == 1)
		{
			int temp = m[i][1];
			m[i][1] = m[i][2];
			m[i][2] = temp;
		}
		cout << m[i][1] << " ";
	}

	cout << "\n";
}