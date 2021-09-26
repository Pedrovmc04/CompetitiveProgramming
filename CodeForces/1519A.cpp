#include <bits/stdc++.h>

using namespace std;

int t;

int32_t main()
{
	cin >> t;

	for(; t > 0 ; --t)
	{
		int a,b,c;
		cin >> a >> b >> c;
		if(a > b)swap(a,b);

		int x = b/a;
		if(b%a >= 1)x++;
		
		if(x-1 <= c)
		{
			cout << "YES\n";
		}else
		{
			cout << "NO\n";
		}

	}

	return 0;
}