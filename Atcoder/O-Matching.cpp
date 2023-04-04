#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int n;
vector<int> graph[maxn];

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> n;

	for(int i = 1 ; i <= n ; ++i)
	{
		for(int j = 1 ; j <= n ; ++i)
		{
			int x;
			cin >> x;
			if(x == 1)graph[i].push_back(j);
		}
	}

	cout << solve(1)

	return 0;
}