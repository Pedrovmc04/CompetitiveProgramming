#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int n,ans;
vector<int> v[5],ans1,ans2;

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> n;

	for(int i = 0 ; i < n ; ++i)
	{
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		v[0].pb(a),v[1].pb(b);
		v[2].pb(c),v[3].pb(d);
	}

	for(int i = 0 ; i < n ; ++i)
	{
		for(int j = 0 ; j < n ; ++j)
		{
			ans1.pb(v[0][i]+v[1][j]);
			ans2.pb(v[2][i]+v[3][j]);		
		}
	}

	int x = (int)ans1.size();

	sort(ans2.begin(),ans2.end());

	for(int i = 0 ; i < x ; ++i)
	{
		int up = upper_bound(ans2.begin(),ans2.end(),-ans1[i]) - ans2.begin();
		int low = lower_bound(ans2.begin(),ans2.end(),-ans1[i]) - ans2.begin();
		ans += up - low;
	}

	cout << ans << "\n";

	return 0;
}