#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back

typedef int64_t ll;
typedef pair<int,int> pii;

const int maxn = 1e4;

int n,last,ans;
vector<pii> v;

bool cmp(pii a , pii b){return a.S < b.S;}

int32_t main()
{
    ios::sync_with_stdio(false),cin.tie(NULL);
   
    cin >> n;

    for(int i = 1 ; i <= n ; ++i)
    {
    	int a,b;
    	cin >> a >> b;
    	v.pb({a,b});
    }

    sort(v.begin(), v.end(),cmp);

    for(auto u : v)
    {
    	if(u.F >= last)
    	{
    		last = u.S;
    		ans++;
    	}
    }

    cout << ans << "\n";

    return 0;
}	