#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{	
	cin >> n;

	while(n > 0)
	{
		int a,b;

		cin >> a >> b;
	
		if(a < b)swap(a,b);


		if(a > 2*b)
		{
			cout << "NO\n";
		}else
		{
			a = a%3;
			b = b%3;

			if(b*2 == a || a*2 == b)
			{
				cout << "YES\n";
			}else
			{
				cout << "NO\n";
			}

		}
		n--;
	}

}