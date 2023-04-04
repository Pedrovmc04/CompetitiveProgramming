#include <bits/stdc++.h>

using namespace std;

const int maxn =1e7+10;

int n ,m;
int ans = 1e8;
int v[maxn];

int busca(){
	int ini = 1 , fim = 1e8;
	int resp = 0;

	while(ini <= fim)
	{
		int meio = (ini+fim)/2;
		resp = 0;
		for(int i = 1 ; i <= n ; ++i)
		{
			resp += meio/v[i];
		}

		if(resp >= m){
			ans = meio;
			fim = meio - 1;
		}else ini = meio + 1;
	}

	return ans;
}

int main(){

	cin >> n >> m ;

	for(int i = 1 ; i <= n ; ++i)
	{
		cin >> v[i];
	}
	
	cout << busca() << "\n"; 
	

	return 0;
}