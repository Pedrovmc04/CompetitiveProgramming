#include <bits/stdc++.h>

using namespace std;

int l, c;

int main(){

	cin >> l >> c;

	if(( l%2 == 0 and c%2 == 0) or (l%2 == 1 and c%2 == 1)){
		cout<<"1\n";
	}else{
		cout<<"0\n";
	}


	return 0;
}