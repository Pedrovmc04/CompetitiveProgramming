#include <bits/stdc++.h>

using namespace std;

int n,m,r;
int v[10010];

int sum(int div)
{
    int s = 0;

    for(int i = 0 ; i < m ; ++i) s += v[i]/div;

    return s;
}

int busca(int val){

    int ini = 1, fim = 10000, ans = 0;

    while(ini <= fim)
    {
        int meio = (ini + fim)/2;
        
        int x = sum(meio);

        if(x < val)
        {
            fim = meio - 1;
        }

        else
        {
            ans = meio;
            ini = meio + 1;
        }
    }

    return ans;
}

int main()
{
    cin >> n >> m;

    for(int i = 0 ; i < m ; ++i)
    {
        cin>>v[i];
    }
    
    r = busca(n);

    cout << r << "\n";

    return 0;
}