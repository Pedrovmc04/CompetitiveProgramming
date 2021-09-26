#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back

typedef int64_t ll;

const int maxn = 1e4;

int n,m,ans;

int32_t main()
{
    ios::sync_with_stdio(false),cin.tie(NULL);
   
    cin >> n >> m;

    int a = ceil(sqrt(n));
    int b = ceil(sqrt(m));

    for(int i = a ; i <= b ; ++i)
    {
    	for(int j = 1 ; j <= i ; ++j)
    	{
    		int x = i*i;
    		int y = j*j*j;
    		
    		if(x > m)break;

    		if(x == y)ans++;
    	}
    }

    cout << ans << "\n";

    return 0;
}	