#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int maxn = 5e4+20;

int n,m,cont;
int grau[maxn];
vector<int> graph[maxn],ans;

void Top_Sort()
{
	priority_queue<int, vector<int>,greater<int>> pq;

	for(int i = 1 ; i <= n ; ++i)
		if(!grau[i])pq.push(i);

	while(!pq.empty())
	{
		cont++;
		int u = pq.top();
		pq.pop();

		for(auto v : graph[u])
		{
			grau[v]--;
			if(!grau[v])pq.push(v);
		}
		ans.push_back(u);
	}


}

int32_t main()
{
	//ios::sync_with_stdio(false),cin.tie(0);

	cin >> n >> m;

	for(int i = 1 ; i <= m ; ++i)
	{
		int a,b;
		cin >> a >> b;
		a++;
		b++;
		grau[b]++;
		graph[a].pb(b);
	}

	Top_Sort();

	if(cont < m)
	{
		cout << "*\n";
	}else{
		for(int i = 0 ; i < n ; ++i)cout << ans[i]-1 << "\n";		
	}
 
	return 0;
}