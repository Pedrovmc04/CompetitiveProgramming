#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back

typedef int64_t ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;

const int maxn = 2e5;

bool flag = true;
int n,k,ans;
vector<pii> v;

int bb(int x)
{
	int ini = 0,fim = n-1,meio;

	while(ini <= fim)
	{
		meio = (ini+fim)>>1;

		if(v[meio].F == x)return v[meio].S;
		if(v[meio].F < x)ini = meio+1;
		if(v[meio].F > x)fim = meio-1;
	}

	return -1;
}

int32_t main()
{
    ios::sync_with_stdio(false),cin.tie(NULL);
   
    cin >> n >> k;

    for(int i = 0 ; i < n ; ++i)
    {
    	int a;
    	cin >> a;
    	v.pb({a,i});
    }

    sort(v.begin(), v.end());

    for(int i = 0 ; i < n ; ++i)
    {
    	int a = bb(k-v[i].F);

    	if(a != -1 && a != v[i].S)
    	{
    		cout << v[i].S+1 << " " << a+1 << "\n";
    		flag = false;
    		break;
    	}
    }

	if(flag)cout << "IMPOSSIBLE\n";

    return 0;
}		