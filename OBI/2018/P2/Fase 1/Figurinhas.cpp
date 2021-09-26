#include <bits/stdc++.h>

using namespace std;

int n,m,c;
set<int> f;

int main()
{
	cin >> n >> m >> c;

	for(int i = 1 ; i <= m ; ++i)
	{
		int a;
		cin >> a;
		f.insert(a);
	}

	for(int i = 1 ; i <= c ; ++i)
	{
		int a;
		cin >> a;
		if(f.find(a) != f.end())f.erase(a);
	}

	cout << f.size() << "\n";

	return 0;
}