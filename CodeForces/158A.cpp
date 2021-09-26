#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e2+10;

int n,q;
int v[maxn];

int main()
{
	cin >> n >> q;

	for(int i = 1 ; i <= n ; ++i)
	{
		cin >> v[i];
	}

	for(int i = 1 ; i <= n ; ++i)
	{
		if(v[i] > q)
		{
			cout << i << " ";
		}
	}

	cout << "\n";


	return 0;
}