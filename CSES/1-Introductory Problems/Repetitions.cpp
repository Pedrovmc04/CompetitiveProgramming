#include <bits/stdc++.h>

using namespace std;

string n;
int cont=1,ans;

int main()
{
	cin >> n;

	for(int i = 1 ; i < (int)n.size() ; ++i)
	{
		if(n[i] != n[i-1])
		{
			ans = max(ans,cont);
			cont = 0;
		}
		cont++;
	}
	ans = max(ans,cont);

	cout << ans << "\n";

	return 0;
}