#include <bits/stdc++.h>

using namespace std;

int a,b,c,d,ans;

int main()
{
	cin >> a >> b;
	cin >> c >> d;


	ans += b-a;
	ans += d-c;
	ans -= max(min(b,d) - max(a,c), 0);

	cout << ans << "\n";

	return 0;
}