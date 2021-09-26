#include <bits/stdc++.h>
#define mid ((l+r)/2)
#define L (2*u)
#define R (2*u+1)
using namespace std;

const int maxn = 1e5+10;

int n,m;
int v[maxn],seg[4*maxn];

void build(int u , int l , int r)
{
	if(l == r)
	{
		seg[u] = v[l];
		return;
	}

	build(L,l,mid);
	build(R,mid+1,r);
	seg[u] = seg[L]*seg[R];
}

void update(int u , int l , int r , int x , int y)
{
	if(l == r)
	{
		seg[u] = y;
		return;
	}

	if(x <= mid)
	{
		update(L,l,mid,x,y);
	}else if(x > mid)
	{
		update(R,mid+1,r,x,y);
	}

	seg[u] = seg[L]*seg[R];
}

int query(int u , int l , int r , int ql , int qr)
{
	if(l > qr || ql > r)return 1;
	if(l >= ql && qr >= r)return seg[u];

	return query(L,l,mid,ql,qr)*query(R,mid+1,r,ql,qr);
}


int main()
{
	//ios_base::sync_with_stdio(false);cin.tie(NULL);

	while(cin >> n >> m)
	{
		for(int i = 1 ; i <= n ; ++i)
		{
			int a;
			cin >> a;

			if(a > 0){

				v[i] = 1;

			}else if(a < 0){

				v[i] = -1;

			}else{

				v[i] = 0;

			}
		}

		build(1,1,n);

		for(int i = 1 ; i <= m ; ++i)
		{
			int a,b;
			char c;

			cin >> c >> a >> b;

			if(c == 'C')
			{
				if(b > 0)b = 1;
				else if(b < 0)b = -1;
				else if(b == 0)b = 0;

				update(1,1,n,a,b);

			}else if(c == 'P')
			{
				//cout << "entreiiiii\n";
				if(query(1,1,n,a,b) < 0)
				{
					cout << "-";
				}else if(query(1,1,n,a,b) > 0)
				{
					cout << "+";
				}else if(query(1,1,n,a,b) == 0)
				{
					cout << "0";
				}
			}
		}

		cout << "\n";

		memset(v,0,sizeof(v));
	}
}
