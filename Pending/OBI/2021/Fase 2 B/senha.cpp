#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int n,m,k,c,p;
double t;
string pass,ans;
vector<string> key;

int32_t main()
{
	//ios::sync_with_stdio(false),cin.tie(0);

	cin >> n >> m >> k;

	cin >> pass;

	for(int i = 0 ; i < m ; ++i)
	{
		string a;
		cin >> a;
		key.pb(a);
	}

	cin >> p;

	c = m;
	t = (double)p;

	while(c)
	{
		int x = p%k;

		if(x == 0)
		{
			ans += key[c-1][k-1];
		}else
		{
			ans += key[c-1][x-1];
		}

		t = ceil(t/k);
		p = (int)t;
		c--;
		//cout << p << "\n";
	}

	for(int i = n-1 ; i >= 0 ; --i)
	{
		if(pass[i] == '#')
		{
			pass[i] = ans[c];
			c++;
		}
	}

	cout << pass << "\n";

	return 0;
}