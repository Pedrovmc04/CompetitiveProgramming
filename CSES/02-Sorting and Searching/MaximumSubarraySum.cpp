#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back

typedef int64_t ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;

const int maxn = 2e5+10;
const int INF = 0x3f3f3f3f;

ll n,aux,ans;
ll v[maxn];

int32_t main()
{
    ios::sync_with_stdio(false),cin.tie(NULL);
   
    cin >> n;

    aux = INF;
    ans = -INF;

    for(int i = 1 ; i <= n ; ++i)cin >> v[i],v[i] += v[i-1];

   	for(int i = 0 ; i <= n ; ++i)
   	{
   		ans = max(ans,v[i]-aux);
   		aux = min(aux,v[i]);
   	}

   	cout << ans << "\n";

    return 0;
}	