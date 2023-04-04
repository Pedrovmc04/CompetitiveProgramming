#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int maxn = 1e5+20;

typedef pair<int,int> pii;

int n;
int mark[maxn];
pii m[maxn];

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> n;

	for(int i = 1 ; i <= n ; ++i)
	{
		cin >> m[i].F;
		m[i].S = i;
	}
	m[n+1].S = n+1;

	sort(m,m+n+2);

	int atual = 2;
	int ans = 2;

	for(int i = 0 ; i <= n ; ++i)
	{
		int y = m[i].F; // Altura
		int x = m[i].S; // Posição

		if(x >= 1 && x <= n && !mark[x-1] && !mark[x+1])atual++;
		if(x >= 1 && x <= n && mark[x-1] && mark[x+1])atual--;

		ans = max(ans,atual);

		mark[x] = 1;
	}

	cout << ans << "\n";

	return 0;
}