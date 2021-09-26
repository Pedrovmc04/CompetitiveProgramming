#include <bits/stdc++.h>

using namespace std;

int n,ans;
stack<int> v;

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> n;

	for(int i = 1 ; i <= n ; ++i)
	{
		int a;
		cin >> a;

		if(a == 0)v.pop();
		else v.push(a);
	}

	while(!v.empty())
	{
		ans += v.top();
		v.pop();
	}

	cout << ans << "\n";

	return 0;
}