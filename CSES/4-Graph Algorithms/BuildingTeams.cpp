#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+10;

bool flag;
int n,q;
int mark[maxn],cor[maxn];
vector<int> graph[maxn];

void bfs(int x)
{
	queue<int> fila1;
	queue<int> fila2;

	fila1.push({x});

	while(true)
	{
		while(!fila1.empty())
		{
			int u = fila1.front();
			fila1.pop();

			cor[u] = 1;
			mark[u] = 1;

			for(auto x : graph[u])
			{
				if(cor[x] == 1)flag = true;
				if(mark[x])continue;
				fila2.push(x);
			}
		}

		while(!fila2.empty())
		{
			int u = fila2.front();
			fila2.pop();

			cor[u] = 2;
			mark[u] = 1;

			for(auto x : graph[u])
			{
				if(cor[x] == 2)flag = true;
				if(mark[x])continue;
				fila1.push(x);
			}
		}

		if(fila1.empty() && fila2.empty())break;
	}
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> q;

	for(int i = 1 ; i <= q ; ++i)
	{
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for(int i = 1 ; i <= n ; ++i)
	{
		if(!mark[i])
		{
			bfs(i);
		}
	}

	if(flag)
	{
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	for(int i = 1 ; i <= n ; ++i)
	{
		cout << cor[i] << " ";
	}

	cout << "\n";

	return 0;
}