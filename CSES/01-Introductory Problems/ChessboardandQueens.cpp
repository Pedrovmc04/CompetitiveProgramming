#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int ways;
bool col[16],diag1[16],diag2[16],reserverd[16][16];

void solve(int r)
{
	if(r == 8)
	{
		ways++;
		return;
	}

	for(int i = 0 ; i < 8 ; ++i)
	{
		if(col[i] || diag1[r+i] || diag2[r-i+7] || reserverd[r][i])continue;

		col[i] = true;
		diag1[r+i] = true;
		diag2[r-i+7] = true;

		solve(r+1); 

		col[i] = false;
		diag1[r+i] = false;
		diag2[r-i+7] = false;
	}
}

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	for(int i = 0 ; i < 16 ; ++i)
	{
		col[i] = false;
		diag1[i] = false;
		diag2[i] = false;
	}

	for(int i = 0 ; i < 8 ; ++i)
	{
		for(int j = 0 ; j < 8 ; ++j)
		{
			char x;
			cin >> x;

			if(x != '.')reserverd[i][j] = true;
		}
	}

	solve(0);

	cout << ways << "\n";

	return 0;
}