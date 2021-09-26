#include <bits/stdc++.h>

using namespace std;

string alph,n,ans;

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0);

	cin >> n;

	alph = "bcdfghjklmnpqrstvxzz";

	for(int i = 0 ; i < (int)n.size() ; ++i)
	{
		if(n[i] == 'a' || n[i] == 'e' || n[i] == 'i' || n[i] == 'o' || n[i] == 'u')
		{
			ans += n[i];
			continue;
		}

		int x = n[i]-'a';

		ans += n[i];

		if(x <= 2)ans+="a";
		else if(x <= 6)ans+="e";
		else if(x <= 11)ans+="i";
		else if(x <= 17)ans+="o";
		else ans+="u";

		for(int j = 0 ; j < (int)alph.size() ; ++j)
		{
			if(alph[j] == n[i])
			{
				ans += alph[j+1];
				break;
			}
		}
	}


	cout << ans << "\n";

	return 0;
}