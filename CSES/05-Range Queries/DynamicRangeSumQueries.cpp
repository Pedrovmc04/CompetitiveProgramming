#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+10;

int n,q;
long long v[maxn],tree[4*maxn];

void build(int node,int l, int r)
{
	if(l == r)
	{
		tree[node] = v[l];
		return;
	}

	int mid = (l+r)>>1;

	build(2*node,l,mid);
	build(2*node+1,mid+1,r);

	tree[node] = tree[2*node] + tree[2*node+1];
}

long long query(int node, int tl , int tr , int l , int r)
{
	if (tl > r || tr < l) return 0;
	if (tl >= l && tr <= r) return tree[node];

	int mid = (tl+tr)>>1;

	return query(2*node,tl,mid,l,r)+query(2*node+1,mid+1,tr,l,r);
}

void update(int node , int l , int r, int pos , int v)
{
	if(l == r)
	{
		tree[node] = v;
		return;
	}

	int mid = (l+r)>>1;

	if(pos <= mid)update(2*node,l,mid,pos,v);
	else update(2*node+1,mid+1,r,pos,v);

	tree[node] = tree[2*node] + tree[2*node+1];
}

int main()
{
	cin >> n >> q;

	for(int i = 1 ; i <= n ; ++i)
	{
		cin >> v[i];
	}

	build(1,1,n);

	for(int i = 1 ; i <= q ; ++i)
	{
		int a,b,c;
		cin >> c >> a >> b;

		if(c == 1)
		{
			update(1,1,n,a,b);
		}else
		{
			cout << query(1,1,n,a,b) << "\n";
		}
	}

	return 0;
}