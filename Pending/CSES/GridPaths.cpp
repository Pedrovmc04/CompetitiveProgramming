#include <bits/stdc++.h>

using namespace std;

string path,ans;
int m[10];

/*void solve(int x)
{
	if(x == n)ans = path;

	if(path[x+1] != "?")
	{
		solve(x+1);
		return;
	}

	for(int i = 0 ; i <= 4 ; ++i)
}*/

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> path;


	//solve(0);

	for(auto v : path)
	{
		if(v == 'D')m[1]++;
		if(v == 'R')m[2]++;
		if(v == 'U')m[3]++;
		if(v == 'L')m[4]++;
	}

	for(int i = 1 ; i <= 4 ; ++i)cout << m[i] << "\n";

	return 0;
}