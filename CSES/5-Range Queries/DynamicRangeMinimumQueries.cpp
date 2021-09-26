#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+10;
const int INF = 0x3f3f3f3f;

int n,q;
int v[maxn],tree[4*maxn];

void build(int node , int l , int r)
{
	if(l == r){
		tree[node] = v[l];
		return;
	}

	int mid = (l+r)>>1;

	build(2*node,l,mid);
	build(2*node+1,mid+1,r);

	tree[node] = min(tree[2*node],tree[2*node+1]);
}

int query(int node, int tl , int tr , int l , int r)
{
	if(tl > r || tr < l)return INF;
	if(tl >= l && tr <= r)return tree[node];

	int mid = (tl+tr)>>1;

	int p1 = query(2*node,tl,mid,l,r);
	int p2 = query(2*node+1,mid+1,tr,l,r);

	return min(p1,p2);
}

void update(int node, int l , int r , int pos , int val)
{
	if(l == r){
		tree[node] = val;
		return;
	}

	int mid = (l+r)>>1;

	if(pos <= mid)update(2*node,l,mid,pos,val);
	else update(2*node+1,mid+1,r,pos,val);

	tree[node] = min(tree[2*node],tree[2*node+1]);
}

int main()
{
	cin >> n >> q;

	for(int i = 1 ; i <= n ; ++i)cin >> v[i];

	build(1,1,n);

	for(int i = 1 ; i <= q ; ++i)
	{
		int a,b,c;
		cin >> c >> a >> b;
		if(c == 1)update(1,1,n,a,b);
		else
		{
			cout << query(1,1,n,a,b) << "\n";
		}
	}

	return 0;
}