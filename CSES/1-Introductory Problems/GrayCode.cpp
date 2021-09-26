#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> arr;

int main()
{
	cin >> n;
 
    arr.push_back("0");
    arr.push_back("1");
 

    for (int i = 2; i < (1<<n); i = i<<1)
    {
        for (int j = i-1 ; j >= 0 ; j--)
            arr.push_back(arr[j]);

        for (int j = 0 ; j < i ; j++)
            arr[j] = "0" + arr[j];
 
        for (int j = i ; j < 2*i ; j++)
            arr[j] = "1" + arr[j];
    }
 
    for (int i = 0 ; i < (int)arr.size() ; i++ )
        cout << arr[i] << endl;

	return 0;
}