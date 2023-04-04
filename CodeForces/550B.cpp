#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;

const int maxn = 20;
const int INF = 0x3f3f3f3f;

int n,l,r,x;
int v[maxn];
ll ans;

int main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> n >> l >> r >> x;

	for(int i = 0 ; i < n ; ++i)cin >> v[i];

	for(int mask = 0 ; mask <= (1<<n) - 1 ; ++mask)
	{
		int maior = 0,menor = INF;
		ll s = 0; 

		for(int i = 0 ; i < n ; ++i)
		{
			if(mask & (1 << i))
			{
				s += v[i];
				menor = min(menor,v[i]);
				maior = max(maior,v[i]);
			}
		}
		if(s >= l && s <= r && (maior-menor) >= x)ans++;
	}

	cout << ans << "\n";

	return 0;
}