#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+10;

int v[maxn],mark[maxn],ans[maxn];
int check,impar;
string n;


int main()
{
	cin >> n;

	int u = (int)n.size();

	for(int i = 0 ; i < u ; ++i)
	{
		int x = n[i]-'A';
		v[i] = x;
		mark[x]++;
	}

	for(int i = 0 ; i <= 25 ; ++i)
	{
		if(mark[i]%2 == 1)
		{
			check++;
			impar = i;
		}
	}

	memset(ans,-1,sizeof(ans));


	if((u%2 == 0 && check != 0) || (u%2 == 1 && check != 1))
	{
		cout << "NO SOLUTION\n";
	}else
	{
		sort(v,v+u);

		if(u%2 == 0)
		{
			for(int i = 0 ; i < u ; i += 2)
			{
				ans[i] = v[i];
				ans[u-i-1] = v[i+1];
			}
		}else
		{
			int t = 0;
			for(int i = 0 ; i < u ; i+=2)
			{
				if(v[i] == impar)continue;
				
				ans[t] = v[i];
				ans[u-t-1] = v[i];
				t++;
			}
		}

		for(int i = 0 ; i < u ; ++i)
		{
			if(ans[i] == -1)ans[i] = impar;
			char x = 'A'+ans[i];
			cout << x;
		}

		cout << "\n";
	}


	return 0;
}