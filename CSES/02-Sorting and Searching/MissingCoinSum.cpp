#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back

typedef int64_t ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;

const int maxn = 2e5+10;

ll n,ans = 1;
ll v[maxn];

int32_t main()
{
    ios::sync_with_stdio(false),cin.tie(NULL);
   
    cin >> n;

    for(int i = 0 ; i < n ; ++i)cin >> v[i];

    sort(v,v+n);

	for(int i = 0 ; i < n ; ++i)
	{
		if(ans < v[i])break;
		ans += v[i];
	}

	cout << ans << "\n";

    return 0;
}	