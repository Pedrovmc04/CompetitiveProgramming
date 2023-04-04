
#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef pair<int,int> pii;

int ans[10];
pii v[10];

int main()
{
	for(int i = 1 ; i <= 2 ; ++i)
	{
		cin >> v[i].F >> v[i].S;
	}

	for(int i = 1 ; i <= 2 ; ++i)
	{
		int a =v[i].F - v[i].S; 
		ans[i] = v[i].F + v[i].S;

		if(a == 1 or a == -1)
		{
			ans[i] = ans[i]*3;
		}else if(a == 0)
		{
			ans[i] = ans[i]*2;
		}
	}

	if(ans[1] > ans[2])
	{
		cout << "Lia\n";
	}else if(ans[1] < ans[2])
	{
		cout << "Carolina\n";
	}else
	{
		cout << "empate\n";
	}


	return 0;
}