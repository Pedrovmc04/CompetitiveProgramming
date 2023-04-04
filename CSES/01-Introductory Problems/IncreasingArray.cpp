#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+10;

long long int n,ans;
int m[maxn];

int main()
{
	cin >> n;

	for(int i = 1 ; i <= n ; i++)
	{
		cin >> m[i];
	}

	for(int i = 1 ; i <= n ; i++)
	{
		if(m[i-1] > m[i])
		{
			ans += m[i-1]-m[i];
			m[i] = m[i-1];
		}
	}

	cout << ans << "\n";

	return 0;
}