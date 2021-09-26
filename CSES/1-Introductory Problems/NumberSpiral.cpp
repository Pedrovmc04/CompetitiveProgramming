#include <bits/stdc++.h>

using namespace std;

unsigned long long n,l,c;

int main()
{
	cin >> n;

	while(n > 0)
	{
		cin >> l >> c;

		if(l >= c)
		{
			unsigned long long x = (l*l);
			unsigned long long y = (l-1)*(l-1)+1;

			if(l%2 == 0)
			{
				cout << x-(c-1) << "\n";
			}else
			{
				cout << y+(c-1) << "\n";
			}

		}else
		{
			unsigned long long x = (c*c);
			unsigned long long y = (c-1)*(c-1)+1;
			
			if(c%2 == 0)
			{
				cout << y+(l-1) << "\n";
			}else
			{
				cout << x-(l-1) << "\n";
			}
		}

		n--;
	}

	return 0;
}