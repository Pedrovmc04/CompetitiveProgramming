#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+10;

long long int n,ans,temp = -1;
long long int v[maxn];

int main()
{
	cin >> n;

	for(int i = 0 ; i < n ; ++i)
	{
		cin >> v[i];
	}

	sort(v,v+n);

	for(int i = 0 ; i < n ; ++i)
	{
		if(temp != v[i])
		{
			ans++;
			temp = v[i];
		}
	}

	cout << ans << "\n";

	return 0;
}