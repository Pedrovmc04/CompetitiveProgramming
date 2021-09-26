#include <bits/stdc++.h>

using namespace std;

long long n;

long long solve(int x)
{
    long long k = x*x;
    k = (k*(k-1));
    long long ans = k - 8 - 24 - (x-4)*16 - 16 - (x-4)*24 - (x-4)*(x-4)*8;
    return ans/2;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n;

	for(int i = 1 ; i <= n ; ++i)
    {
        if(i == 1)
        {
            cout << "0\n";
        }else if(i == 2)
        {
            cout << "6\n";
        }else if(i == 3)
        {
            cout << "28\n";
        }else
        {
            cout << solve(i) << "\n";
        }
    }

	return 0;
}