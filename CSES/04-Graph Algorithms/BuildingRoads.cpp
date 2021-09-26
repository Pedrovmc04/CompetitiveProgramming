#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

const int maxn = 2e5+10;

int n,m;
int mark[maxn];
vector<int> graph[maxn],ans;

void dfs(int x)
{
	if(mark[x])return;

	mark[x] = 1;

	for(auto xx : graph[x])
	{
		dfs(xx);
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;

	for(int i = 1 ; i <= m ; ++i)
	{
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for(int i = 1 ; i <= n ; ++i)
	{
		if(mark[i])continue;
		ans.push_back(i);
		dfs(i);
	}
	int u = (int)ans.size()-1;

	cout << u << "\n";

	for(int i = 0 ; i < u ; ++i)
	{
		cout << ans[i] << " " << ans[i+1] << "\n";
	}

	return 0;
}