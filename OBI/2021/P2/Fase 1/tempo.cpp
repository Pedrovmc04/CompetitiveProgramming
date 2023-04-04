#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second

typedef pair<char,int> pci;
typedef pair<int,int> pii;

const int maxn = 1e2+10;

bool flag = false;
int n;
int ans[maxn],mark[maxn];
vector<pci> v;
vector<pii> q;

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	memset(ans,-1,sizeof(ans));

	cin >> n;

	for(int i = 0 ; i < n ; ++i)
	{
		char a;
		int b;

		cin >> a >> b;
		v.pb({a,b});

		if(a == 'R')
		{
			q.pb({b,i});
			ans[b] = -1;
			mark[b] = 1;
		}else if(a == 'E')
		{
			ans[b] = 0;
		}
	}

	for(pii u : q)
	{
		if(ans[u.F] == -1)continue;
		int sum = 0;
		for(int i = u.S ; i < n ; ++i)
		{
			if(v[i].F == 'E' && v[i].S == u.F)break;

			if(v[i+1].F != 'T')sum++;
			else
			{
				sum+= v[i+1].S;
				++i;
			}
		}
		ans[u.F]+=sum;
	}

	for(int i = 1 ; i <= 100 ; ++i)
	{
		if(mark[i] == 1)cout << i << " " << ans[i] << "\n";
	}

	return 0;
}