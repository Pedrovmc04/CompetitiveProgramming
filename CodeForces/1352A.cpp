#include <bits/stdc++.h>

using namespace std;

int n,ans,x;
vector<int> v;
string m; 

int main()
{
	cin >> n;

	for(int i = 1 ; i <= n ; ++i)
	{
		cin >> m;

		for(int j = 0 ; j <= (int)m.size() ; ++j)
		{
			if(m[j] > '0')ans++;
		}

		cout << ans << "\n";

		for(int j = (int)m.size()-1 ; j >= 0 ; --j)
		{
			if(m[j] > '0')
			{
				x = m[j]-'0';

				v.push_back(x*pow(10,m.size()-j-1));
			}
		}

		for(int j = (int)v.size()-1 ; j >= 0 ; --j)
		{
			cout << v[j] << " ";
		}

		cout << "\n";

		m.clear();
		v.clear();
		ans = 0;
	}

	return 0;
}