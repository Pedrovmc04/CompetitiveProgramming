#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back

typedef int64_t ll;

const int maxn = 2e4+10;

int n,ans;
string m[maxn];

bool cmp(string a,string b){ return ((int)a.size()) < ((int)b.size()); }

int32_t main()
{
    ios::sync_with_stdio(false),cin.tie(NULL);
   
    cin >> n;

    for(int i = 0 ; i < n ; ++i)cin >> m[i];

    sort(m,m+n,cmp);

	for(int i = 0 ; i < n ; ++i)
	{
		for(int j = i+1 ; j < n ; ++j)
		{
			if(m[j].find(m[i]) != string::npos)ans++;
			if(m[j] == m[i])ans++;
		}
	}

	cout << ans << "\n";

    return 0;
}	