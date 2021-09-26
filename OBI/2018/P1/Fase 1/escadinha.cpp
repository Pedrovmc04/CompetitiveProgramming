 #include <bits/stdc++.h>

 using namespace std;

 const int maxn = 1e3+10;

 int n,ans,seq;
 int v[maxn];

 int main()
 {
     cin >> n ;

     for(int i = 1 ; i <= n ; ++i)
     {
         cin >> v[i];
     }

     ans = 1;

     if(n == 1)
     {
         cout << ans << "\n";
     }else
     {
         seq = v[2]-v[1];
         for(int i = 2 ; i <=n ; ++i)
         {
             if(v[i]-v[i-1] != seq)
             {
                 seq = v[i] - v[i-1];
                 ans++;
             }
         }
         cout << ans << "\n";
     }

 } 
