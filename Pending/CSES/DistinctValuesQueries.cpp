#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back

typedef int64_t ll;

const int maxn = 2e5+10;

struct querrys
{
	int l,r,id;

	bool operator<(querrys x){return r < x.r;}
};

int n,m,c;
int v[maxn],tree[4*maxn];
querrys q[maxn];
map<int, int> mp;

void update(int node, int tl, int tr, int pos, int u){

    if(tl==tr){
        tree[node] += u;
        return;
    }

    int mid = (tl+tr)>>1;

    if(pos <= mid) update(2*node,tl,mid,pos,u);
    else update(2*node+1,mid+1,tr,pos,u);

    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node, int tl, int tr, int l, int r){

    if(r<tl or l>tr) return 0;

    if(l<=tl and r>=tr) return tree[node];

    int mid = (tl+tr)>>1;

    return query(2*node, tl, mid, l, r)+query(2*node+1, mid+1, tr, l, r);
}

int32_t main()
{
    ios::sync_with_stdio(false),cin.tie(NULL);
   
    cin >> n >> m;

    for(int i = 1 ; i <= n ; ++i)
    {
    	cin >> v[i];

    	if(mp.find(v[i]) == mp.end())mp[v[i]] = ++c;
    	v[i] = mp[v[i]]; 
    }

    for(int i = 1 ; i <= m ; ++i)
    {
    	cin >> q[i].l >> q[i].r;
    	q[i].id = i;
    }

    sort(q+1,q+m+1);

    

    cout << endl;

    return 0;
}