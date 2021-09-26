#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3+10;

int ant,prox;
int n , ans;
int v[maxn];

int main()
{
	cin >> n;

	for(int i = 1 ; i <= n ; ++i)
	{
		cin >> v[i];
	}

	for(int i = 2 ; i < n ; ++i)
	{
		ant = i-1;
		prox = i+1;
		if(v[prox] > v[i] and v[ant] > v[i]) ans = 1;
	}

	if(ans == 1)
	{
		cout << "S\n";
	}else
	{
		cout << "N\n";
	}


	return 0;

}