#include <bits/stdc++.h>

using namespace std;

int c,n,contador;

int main()
{
	cin >> c >> n;

	int x = c-1;

	while(n>0)
	{
		n -= x;
		contador++;
	}

	cout << contador << "\n";


	return 0;
}