#include <bits/stdc++.h>

using namespace std;

int n,x;
vector<int> v;
bool flag = true;

int main()
{
	cin >> n;

	for(int i = 1 ; i <= n ; ++i)
	{
		cin >> x;

		for(int j = 2 ; j <= x/2 ; ++j)
		{

			if(x%j == 0)
			{
				v.push_back(j);
				x = x/j;
			}

			if(v.size() == 2)
			{
				v.push_back(x);
				break;
			}

		}

		if(v.size() == 3)
		{
			for(int j = 0 ; j < v.size()-1 ; ++j)
			{
				if(v[j] == v[2])flag = false;
			}
		}


		if(v.size() == 3 && flag)
		{
			cout << "YES\n";
			for(int j = 0 ; j < v.size() ; ++j)
			{
				cout << v[j] << " ";
			}
			cout << "\n";

		}else
		{
			cout << "NO\n";
		}

		v.clear();
		x = 0;
		flag = true;
	}

	return 0;
}  