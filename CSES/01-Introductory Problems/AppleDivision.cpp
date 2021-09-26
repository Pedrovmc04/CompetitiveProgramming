#include <bits/stdc++.h>

using namespace std;

const int maxn = 30;

long long n,aux;
long long v[maxn];

long long solve(long long val,int k)
{
	if(k > n)
	{
		long long a = (aux-val);
		long long diff;

		if(val >= a)diff = val-a;
		else diff = a-val;
		
		return diff;
	}

	long long ncoloca = solve(val,k+1);

	long long coloca = solve(val+v[k],k+1);


	return min(coloca,ncoloca);
}

int main()
{
	cin >> n;

	for(int i = 1 ; i <= n ; ++i)
	{
		cin >> v[i];
		aux += v[i];
	}

	cout << solve(0,1) << "\n";

	return 0;
}