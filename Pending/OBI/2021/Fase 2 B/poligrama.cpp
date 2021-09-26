#include <bits/stdc++.h>

using namespace std;

bool flag = true;
int n;
string w;

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> n >> w;

	string x = "";
	string y = "";
	string z = "";

	if(n%2)
	{
		z += w[0];

		for(int i = 0; i < n ; ++i)if(w[i] != z[0])flag =false;
	}else
	{
		for(int i = 0 ; i < n/2 ; ++i)
		{
			x += w[i];
		 	z += w[i];
		}

		for(int i = n/2 ; i < n ; ++i)y += w[i];


		sort(x.begin(), x.end());
		sort(y.begin(), y.end());

		if(x != y)flag = false;
	}

	if(flag)
	{
		cout << z << "\n";
	}else
	{
		cout << "*\n";
	}

	return 0;
}