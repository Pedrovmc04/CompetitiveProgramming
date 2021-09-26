#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int maxn = 1e5+10;

int n,q;
bool aux;
int mark[maxn],pai[maxn];
vector<int> graph[maxn],ans;

void dfs(int x,int p)
{	
	mark[x] = 1;
	pai[x] = p;

	for(int u : graph[x])
	{
		if(aux)return;
		if(u == p)continue;
		if(mark[u])
		{
			ans.pb(u);
			p = x;
			while(p != pai[u])
			{
				ans.pb(p);
				p = pai[p];
			}
			aux = true;
			return;
		}else
		{
			dfs(u,x);
		}
	}
}

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> n >> q;

	for(int i = 1 ; i <= n ; ++i)
	{
		int a,b;
		cin >> a >> b;
		graph[a].pb(b);
		graph[b].pb(a);
	}

	for(int i = 1 ; i <= n ; ++i)
	{
		if(!mark[i])
		{
			dfs(i,0);
			if((int)ans.size())break;
		}
	}

	//reverse(ans.begin(),ans.end());

	if(ans.size() == 0 || ans.size() == 1)
	{
		cout << "IMPOSSIBLE\n";
	}else
	{
		cout << (int)ans.size() << "\n";
		for(int i : ans)
		{
			cout << i << " ";
		}
		cout << "\n";
	}

	return 0;
}