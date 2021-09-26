#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back

typedef int64_t ll;

const int maxn = 2e5+10;

int n,m,rm,fim,qtd;
int v[maxn],q[maxn];

void solve(int x)
{
	int b = 1;
	while(x*b <= fim)
	{
		v[x*b] = -1;
		rm++;
		b++;
	}
}

int32_t main()
{
    ios::sync_with_stdio(false),cin.tie(NULL);
   
    cin >> n >> m;

    for(int i = 1 ; i <= n ; ++i)v[i] = i;

    for(int i = 1 ; i <= m ; ++i)
    {
    	cin >> q[i];
    	if(q[i] == 2)qtd++;
    }

    if(qtd == m)
    {
    	if(qtd > 29)cout << "1\n";
    	else
    	{
    		int u = 1<<qtd;
    		int v = 1;
    		cout << v << "\n";
    		while(v+u <= n)
    		{
    			v += u;
    			cout << v << "\n";
    		}
    	}
    }else
    {
    	for(int i = 1 ; i <= m ; ++i)
    	{
    		fim = n-rm;
	    	solve(q[i]);

	    	int k = 1;

	    	for(int j = 1 ; j <= fim ; ++j)
	    	{
	    		if(v[j] == -1)continue;

	    		v[k] = v[j];
	    		k++;
	    	}
    	}

    	fim = n-rm;

	    if(fim > 10000)fim = 10000;

	    for(int i = 1 ; i <= fim ; ++i)cout << v[i] << "\n";
    }

    return 0;
}	