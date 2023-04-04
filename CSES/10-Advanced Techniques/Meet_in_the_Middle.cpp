#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define int int64_t

const int maxn = 45;
const int maxl = 22;

int n,m,ans,q;
int v[maxn];
vector<int> ans1,ans2;

int32_t main()
{
	cin >> n >> m;

	int esq = (n+1)>>1 ; 
    int dir = (n>>1) ; 

	for(int i = 0 ; i < n ; ++i)cin >> v[i];

	for(int mask = 0 ; mask < (1<<dir) ; mask++){
        int s = 0 ; 
        for(int i = 0 ; i < dir ; i++){
            if(mask&(1<<i)) s += v[i] ; 
        }
        ans1.push_back(s) ; 
    }

    for(int mask = 0 ; mask < (1<<esq) ; mask++){
        int s = 0 ;
        for(int i = 0 ; i < esq ; i++){
            if(mask&(1<<i)) s += v[i+dir] ; 
        } 
        ans2.push_back(s) ; 
    }

	sort(ans2.begin(),ans2.end());

	for(int i = 0 ; i < ans1.size() ; ++i)
	{
		int x = m - ans1[i];
		int up = upper_bound(ans2.begin(),ans2.end(),x) - ans2.begin();
        int low = lower_bound(ans2.begin(),ans2.end(),x) - ans2.begin();
        ans += abs(low-up) ;
	}

	cout << ans << "\n";

	return 0;
}