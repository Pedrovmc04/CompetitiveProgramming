#include <bits/stdc++.h>

using namespace std;

struct status{
	int F,D; //Força,Dano;
};

status j,k;

int x , y;

int main(){

	cin >> j.F >> j.D;
	cin >> k.F >> k.D;

	x = j.D - k.F;
	y = k.D - j.F;

	if( (x == 0 and y == 0) or (x != 0 and y != 0) ){
		cout << "-1\n";
	}else if( x == 0 and y != 0){
		cout << "1\n";
	}else if( x != 0 and y == 0){
		cout<< "2\n";
	}


	return 0;
}