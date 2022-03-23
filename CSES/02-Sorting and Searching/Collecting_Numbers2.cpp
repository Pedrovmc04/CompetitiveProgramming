#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+10;

int n,m,ans = 1, aux = 1;
int v[maxn],p[maxn];

int main()
{
    cin >> n >> m;

    for(int i = 1 ; i <= n ; ++i)
    {
        cin >> v[i];
        p[v[i]] = i;
    }

    for(int i = 1; i <= n ; ++i)
    {
        if(aux > p[i])ans++;
        aux = p[i];
    }

    for(int i = 1 ; i <= m ; ++i)
    {
        int a,b;
        cin >> a >> b;
        
        int x = v[a], y = v[b];

        swap(v[a],v[b]);

        if(p[x-1] <= p[x] && p[x-1] > b)ans++;
        if(p[x-1] > p[x] && p[x-1] <= b)ans--;
        if(p[x] <= p[x+1] && b > p[x+1])ans++;
        if(p[x] > p[x+1] && b <= p[x+1])ans--;
        p[x] = b;
        if(p[y-1] <= p[x] && p[y-1] > a)ans++;
        if(p[y-1] > p[y] && p[y-1] <= a)ans--;
        if(p[y] <= p[y+1] && a > p[y+1])ans++;
        if(p[y] > p[y+1] && a <= p[y+1])ans--;
        p[y] = a;

        cout << ans << "\n";
    }


    return 0;
}