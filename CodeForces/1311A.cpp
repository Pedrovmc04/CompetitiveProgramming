#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
	cin >> n;

	for(int i = 1 ; i <= n ; ++i)
	{
		int a,b,c,d;
		cin >> a >> b;
		c = a-b;
		d = b-a;

		if(c == 0)
		{
			cout << "0\n";
			continue;
		}

		if(d >= 0)
		{
			if(d%2 == 0)
			{
				cout << "2\n";
				continue;
			}else
			{
				cout << "1\n";
				continue;
			}
		}else
		{
			if(c%2 == 0)
			{
				cout << "1\n";
				continue;
			}else
			{
				cout << "2\n";
				continue;
			}
		}
	}

}