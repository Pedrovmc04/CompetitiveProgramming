#include <bits/stdc++.h>

using namespace std;

int u;
string n;
vector<string> v;

int main()
{
	cin >> n;

	sort(n.begin(),n.end());
	
	v.push_back(n);

	while(next_permutation(n.begin(),n.end()))
	{
		v.push_back(n);
	}

	u = (int)v.size();

	cout << u << "\n";

	for(int i = 0 ; i < u ; ++i)
	{
		cout << v[i] << "\n";
	}

	return 0;
}