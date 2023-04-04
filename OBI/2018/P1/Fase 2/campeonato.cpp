
#include <bits/stdc++.h>

using namespace std;

#define maxn 18

int x,y;

int v[maxn];

int main()
{

	for (int i = 1; i <=16 ; ++i)
	{
		cin >> v[i];
		if(v[i]==1)x = i;
		if(v[i]==9)y = i;
	}

	if((x >= 9 and y <= 8) or (y >= 9 and x <=8))
	{
		cout << "final\n";
	}
	else if((x <= 4 and y >=5) or (y <=4 and x>=5) or (x >=13 and y <=12) or (y >=13 and x <= 12))
	{
		cout << "semifinal\n";
	}else if((x % 2 == 0 and (x+1 == y or x+2 == y)) or (y % 2 == 0 and (y+1 == x or y+2 == x)) or (x % 2 == 1 and (x+2 == y or x+3 == y)) or (y % 2 == 1 and (y+2 == x or y+3 == x)) )
	{
		cout << "quartas\n";
	}else if((x % 2 == 1 and x+1 == y) or (y % 2 == 1 and y+1 == x))
	{
		cout << "oitavas\n";
	}


	return 0;
}