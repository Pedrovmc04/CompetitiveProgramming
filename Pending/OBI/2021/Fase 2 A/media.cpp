#include <bits/stdc++.h>

using namespace std;

int a,b,c;
int v[4];

bool verify()
{
	v[0] = a;
	v[1] = b;
	v[2] = c;

	sort(v,v+3);

	int media = (a+b+c)/3;

	if(media = v[1])return true;

	return false;
}

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> a >> b;

	c = (3*a) - (a+b);

	if(verify())
	{
		cout << c << "\n";
		return 0;
	}
	
	c = (3*b) - (a+b);

	if(verify())
	{
		cout << c << "\n";
		return 0;
	}

	c = (a+b)/2;

	if(verify)cout << c << "\n";

	return 0;
}