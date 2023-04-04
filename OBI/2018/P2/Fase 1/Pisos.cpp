#include <bits/stdc++.h>

using namespace std;

int c,l,ans1,ans2;

int main()
{
	cin >> l >> c;

	ans1 += l*c;
	ans1 += (l-1)*(c-1);

	ans2 += (l-1)*2;
	ans2 += (c-1)*2;

	cout << ans1 << "\n" << ans2 << "\n"; 

	return 0;
}