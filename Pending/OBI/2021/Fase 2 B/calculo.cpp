#include <bits/stdc++.h>

using namespace std;

int s,a,b,ans;

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> s >> a >> b;

	for(int i = a ; i <= b;++i)
	{
		int u = i;
		int soma = 0;

		while(u)
		{
			int x = u%10;
			soma += x;
			u /= 10;
		}

		if(soma == s)ans++;
	}

	cout << ans << "\n";

	return 0;
}