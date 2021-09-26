#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e2+10;
const int LIMIT = 1e4;

typedef int64_t ll;

bool flag;
ll t,n;
ll v[maxn],m[maxn];

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> t;

	for( ; t > 0 ; --t)
	{
		cin >> n;

		flag = true;

		memset(m,-1,sizeof(m));
		m[0] = 0;

		for(int i = 1 ; i <= n ; ++i)
		{
			cin >> v[i];
			if(v[i] == 1)m[i]=1,
			for(int j = 2 ; j <= 100 ; ++j)
			{
				for(int k = 0 ; k <= 14; ++k)
				{
					int x = pow(j,k);
					cout << x << " ";
					if(x > LIMIT)break;
					if(v[i] == x)m[i] = j+m[i-1];
				}
				cout << "\n";
			}
			cout << m[i] << "\n";
		}

		cout << "\n";

		for(int i = 1 ; i < n ; ++i)
		{
			for(int j = i ; j <= n ; ++j)
			{
				if((m[j]-m[i-1])%2 != 0)flag = false;
			}
		}

		if(flag)
		{
			cout << "YES\n";
		}else
		{
			cout << "NO\n";
		}
	}

	return 0;
}