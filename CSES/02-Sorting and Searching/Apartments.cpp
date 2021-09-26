#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

const int maxn = 2e5+10;

int n,m,k,ans,i,j;
int a[maxn],apart[maxn];

int main()
{
    ios::sync_with_stdio(false),cin.tie(0);

	cin >> n >> m >> k;

	for(i = 0 ; i < n ; ++i)cin >> a[i];

    for(j = 0 ; j < m ; ++j)cin >> apart[j];

    sort(a,a+n);
    sort(apart,apart+m);

    i = 0;
    j = 0;

	while(i < n && j < m)
    {
        if(abs(a[i]-apart[j]) <= k)
        {
            ++i,++j;
            ++ans;
        }else if(a[i]-apart[j] > k)
        {
            ++j;
        }else
        {
            ++i;
        }
    }

    cout << ans << "\n";

	return 0;
}