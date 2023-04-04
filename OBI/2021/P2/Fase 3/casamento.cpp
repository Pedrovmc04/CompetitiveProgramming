#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back

typedef int64_t ll;

const int maxn = 1e4;

int sz1,sz2,dif,resp1 = -1,resp2 = -1,divi;
string a,b,ans1,ans2;

int32_t main()
{
    ios::sync_with_stdio(false),cin.tie(NULL);
   
   	cin >> a >> b;

   	sz1 = (int)a.size();
   	sz2 = (int)b.size();
   	dif = sz1 - sz2;
   	if(dif < 0)dif = dif*-1;
   
   	if(sz1 > sz2)
   	{
   		for(int i = 1; i <= dif ; ++i)b = "0"+b;
   	}else if(sz2 > sz1)
   	{
   		for(int i = 1; i <= dif ; ++i)a = "0"+a;
   	}

   	sz1 = (int)a.size();
   	sz2 = (int)b.size();

	for(int i = 0 ; i < sz1 ; ++i)
	{
		int x = (int)(a[i]-'0');
		int y = (int)(b[i]-'0');

		if(x > y){
			ans1 += a[i];
		}else if(x < y){
			ans2 += b[i];
		}else{
			ans1 += a[i];
			ans2 += b[i];
		}
	}

	sz1 = (int)ans1.size();
   	sz2 = (int)ans2.size();

   	divi = 1;

   	if(sz1 > 0)resp1 = 0;
   	if(sz2 > 0)resp2 = 0;

	for(int i = 0 ; i < sz1 ; ++i)
	{
		int x = sz1-i-1;
		int y = (int)(ans1[x]-'0');

		resp1 += y*divi;

		divi = divi*10;
	}
	divi = 1;
	for(int i = 0 ; i < sz2 ; ++i)
	{
		int x = sz2-i-1;
		int y = (int)(ans2[x]-'0');

		resp2 += y*divi;

		divi = divi*10;
	}

	if(resp2 < resp1)swap(resp1,resp2);

	cout << resp1 << " " << resp2 << "\n";

    return 0;
}	