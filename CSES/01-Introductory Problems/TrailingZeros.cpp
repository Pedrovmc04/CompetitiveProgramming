#include <bits/stdc++.h>

using namespace std;

long long n,ans,x = 5;

int main()
{
	cin >> n;

	while(x <= n)
	{
		ans += n/x;
		x = x*5;
	}

	cout << ans << "\n";

	return 0;
}