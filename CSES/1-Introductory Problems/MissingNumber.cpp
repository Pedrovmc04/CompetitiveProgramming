#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+10;

int n;
int m[maxn];

int main()
{
	cin >> n;

	for(int i = 1 ; i < n ; ++i)
	{
		int x;
		cin >> x;
		m[x] = 1;
	}

	for(int i = 1 ; i <= n ; ++i)
	{
		if(m[i] == 0)
		{
			cout << i << "\n";
		}
	}


	return 0;
}