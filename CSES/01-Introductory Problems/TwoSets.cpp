#include <bits/stdc++.h>

using namespace std;

int n,ans1,ans2;
vector<long long> v1,v2;

int main()
{
	cin >> n;

	for(int i = n ; i > 0 ; --i)
	{
		if(ans1 <= ans2)
		{
			ans1 += i;
			v1.push_back(i);
		}else
		{
			ans2 += i;
			v2.push_back(i);
		}
	}

	//cout << ans1 << " " << ans2 << "\n";

	if(ans1 == ans2)
	{
		cout << "YES\n";
		int u1 = (int)v1.size();
		int u2 = (int)v2.size();

		cout << u1 << "\n";
		for(int i = u1-1 ; i >= 0 ; --i)
		{
			cout << v1[i] << " ";
		}

		cout << "\n" << u2 << "\n";
		for(int i = u2-1 ; i >= 0 ; --i)
		{
			cout << v2[i] << " ";
		}
		cout << "\n";

	}else
	{
		cout << "NO\n";
	}

	return 0;
}