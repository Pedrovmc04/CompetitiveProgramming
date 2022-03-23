#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+10;

int n,ans = 1,aux = 1;
int indx[maxn];

int main()
{
    cin >> n;

    for(int i = 1; i <= n ; ++i)
    {
        int x;
        cin >> x;
        indx[x] = i;
    }

    for(int i = 1 ; i <=n ; ++i)
    {
        if(aux > indx[i])ans++;

        aux = indx[i];
    }

    cout << ans << "\n";

    return 0;
}
