#include <bits/stdc++.h>

using namespace std;

int const maxn = 1e5;

int n,m,cont;
int grau[maxn];
vector<int> grafo[maxn];

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;

	for(int i = 0 ; i < m ; ++i)
	{
		int a,b;
		cin >> a >> b;
		grafo[a].push_back(b);
		grau[b]++;
	}


	priority_queue<int, vector<int>,greater<int>> pq;
	vector<int> ans;

	for(int i = 0 ; i < n ; ++i)
	{
		if(grau[i] == 0)
		{
			pq.push(i);
		}
	}

	while(!pq.empty())
	{
		int u = pq.top();
		pq.pop();
		cont++;

		for(auto v : grafo[u])
		{
			grau[v]--;
			if(grau[v] == 0)
			{
				pq.push(v);
			}
		}
	}

	if(ans.size() == n)
	{
		for(int i = 0 ; i < n ; ++i) cout << ans[i] << " ";

		cout << "\n";
	}else
	{
		cout << "n dá";
	}

	return 0;
}