#include <bits/stdc++.h>

#define mid ((l+r)/2)
#define L (2*u+1)
#define R (2*u+2)

using namespace std;

const int maxn = 1e6+10;

struct tree
{
	int f,s,fs,sf;
};

int n,m;
tree seg[4*maxn];
string v,p;

void flush(int u, int l , int r)
{
	if(lazy[u] == "")return;

	seg[u] += lazy[u];

	if(l != r)
	{
		lazy[L] += lazy[u];
		lazy[R] += lazy[u];
	}
	lazy[u] = "";
}

void build(int u , int l , int r)
{
	if(l == r)
	{
		seg[u].sf++;
		seg[u].fs++;
		if(v[l] == "4")
		{
			seg[u].f++; 
		}else if(v[l] == "7")
		{
			seg[u].s++;
		}

		return;
	}

	build(L,l,mid);
	build(R,mid,r);
	seg[u].fs = seg[L].fs + seg[R].s;
	seg[u].s  = seg[R].s;
	seg[u].f  = seg[L].f + seg[R].f;
	sef[u].sf = 
}

void update(int u ,int l,int r,int ql , int qr)
{
	flush(u,l,r);

	if(l > qr || ql > r)return;

	if(l >= ql && qr >= r)
	{
		lazy[u] += 
		flush(u,l,r);
		return;
	}

	update(L,l,mid,ql,qr);
	update(R,mid,r,ql,qr);

	seg[u] = seg[L]+seg[R];
}

long long query(int u,int l, int r , int ql , int qr)
{
	flush(u,l,r);

	if(l > qr || ql > r)return ;
	if(l >= ql && qr >= r)return seg[u];

	return query
}

int main()
{
	cin >> n >> m >> v; 

	build(1,0,n-1);

	for(int i = 1 ; i <= m ; ++i)
	{
		cin >> p

		if(p == "count")
		{
			cout << query() << "\n";
		}else if(p == "switch")
		{
			int a,b;
			cin >> a >> b;
			update(1,0,n-1,a,b);
		}
	}

	return 0;
}