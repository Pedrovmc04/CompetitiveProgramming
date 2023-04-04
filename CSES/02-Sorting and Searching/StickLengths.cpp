#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back

typedef int64_t ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;

const int maxn = 2e5+10;

ll n,mid,ans;
ll v[maxn];

int32_t main()
{
    ios::sync_with_stdio(false),cin.tie(NULL);
   
    cin >> n;

    for(int i = 0 ; i < n ; ++i)cin >> v[i]; 

    sort(v,v+n);

    mid = v[n/2];

    for(int i = 0 ; i < n ; ++i)ans += abs(mid-v[i]);

	cout << ans << "\n";

    return 0;
}	