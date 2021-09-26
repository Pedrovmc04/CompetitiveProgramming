#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int q,k,aux,p,sz=1;

int32_t main()
{
	cin >> q;

	while(q--)
	{
		aux = 0;

		cin >> k;


		for(int i = 1; i <= 18; i++) {
			p = (9ll * pow(10, i-1));
			aux += (p * i);
			if(k <= aux) {
				sz = i;
				break;
			}
		}

		cout << aux << " " << sz << "\n";
	}
	

	return 0;
}