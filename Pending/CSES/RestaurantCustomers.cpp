#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back

typedef int64_t ll;
typedef pair<int,int> pii;

const int maxn = 1e4;

int n,t,ans;
vector<pii> v;

int32_t main()
{
    ios::sync_with_stdio(false),cin.tie(NULL);
   
    cin >> n;

    for(int i = 0 ; i < n ; ++i)
    {
    	int a,b;
    	cin >> a >> b;
    	v.pb({a,1}),v.pb({b,-1});
    }

    sort(v.begin(), v.end());

    for(int i = 0 ; i < (int)v.size() ; ++i)t += v[i].S , ans = max(ans,t);

   	cout << ans << "\n";

    return 0;
}	