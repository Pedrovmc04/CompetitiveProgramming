#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

int n;
vector<pair<int,int>> v;

void solve(int x,int atual,int destino,int aux)
{
	if(x == 1)
	{
		v.push_back({atual,destino});
		return;
	}
	solve(x-1,atual,aux,destino);

	v.push_back({atual,destino});

	solve(x-1,aux,destino,atual);
}

int main()
{
	cin >> n;

	solve(n,1,3,2);

	int u = (int)v.size();

	cout << u << "\n";

	for(int i = 0 ; i < u ; ++i)
	{
		cout << v[i].F << " " << v[i].S << "\n";
	}

	return 0;
}