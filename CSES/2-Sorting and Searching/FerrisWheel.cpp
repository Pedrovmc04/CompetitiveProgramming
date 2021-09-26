#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+10;

int n,p,ans;
int v[maxn];

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> n >> p;

	for(int i = 0 ; i < n ; ++i)cin >> v[i];

	sort(v,v+n);

	int j = 0;

	for(int i = n-1 ; i >= 0 ; --i)
	{
		if(j == i)
		{
			ans++;
			break;
		}
		if(j > i)break;

		if(v[i]+v[j] > p)
		{
			ans++;
		}else
		{
			ans++;
			j++;
		}
	}

	cout << ans << "\n";

	return 0;
}