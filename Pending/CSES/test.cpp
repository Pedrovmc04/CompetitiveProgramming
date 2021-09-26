#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back

typedef int64_t ll;

const int maxn = 1e4;

int32_t main()
{
    ios::sync_with_stdio(false),cin.tie(NULL);
   
    int myints[] = {10,20,30,30,20,10,10,20};
	std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

	std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

	std::vector<int>::iterator low,up;
	low=std::lower_bound (v.begin(), v.end(), 10); //          ^
	up= std::upper_bound (v.begin(), v.end(), 10); //                   ^

	std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
	std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

    return 0;
}	