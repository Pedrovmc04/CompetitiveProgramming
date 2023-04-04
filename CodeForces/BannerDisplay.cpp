#include <bits/stdc++.h>

using namespace std;

int n;
int v[20];

int32_t main()
{
	cin >> n;

	for(int i = 1 ; i <= n ; ++i)
	{
		char a;
		cin >> a;
		if(a == 'c')
		{
			v[0]++;
		}else if(a == 'o')
		{
			v[1]++;
		}else if(a == 'd')
		{
			v[2]++;
		}else if(a == 'e')
		{
			v[3]++;
		}else if(a == 'r')
		{
			v[4]++;
		}else if(a == 'a')
		{
			v[5]++;
		}else if(a == 'm')
		{
			v[6]++;
		}else if(a == 's')
		{
			v[7]++;
		}
	}

	sort(v,v+8);

	cout << v[0] << "\n";
}