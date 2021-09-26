#include <bits/stdc++.h>

using namespace std;

struct point
{
	double x,y;

	point operator- (point b)
	{
		point ans;
		ans.x = x - b.x;
		ans.y = y - b.y;
		return ans;
	}

	bool operator< (point b)
	{
		if(x != b.x)return x < b.x;
		return y < b.y;
	}
};

int n;
double resp;
vector<point> up,down,v;

long long cross(point a , point b , point c)
{
	point p1 = b-a;
	point p2 = c-a;
	return (p1.x*p2.y)-(p1.y*p2.x);
}

int main()
{
	while(true)
	{
		cin >> n;

		if(n == 0)break;

		for(int i = 0 ; i < n ; ++i)
		{
			int x,y;
			cin >> x >> y;
			v.push_back({x,y});
		}

		sort(v.begin(),v.end());

		for(int i = 0 ; i < n ; ++i)
		{
			while(up.size() > 1 && cross(up[up.size()-2] , up[up.size()-1] , v[i]) > 0)up.pop_back();

			up.push_back(v[i]);

			while(down.size() > 1 && cross(down[down.size()-2] , down[down.size()-1] , v[i]) < 0)down.pop_back();

			down.push_back(v[i]);
		}

		for(int i = 1 ; i < (int)up.size() ; ++i)
		{
			point aux;

			aux = up[i-1] - up[i];

			resp += sqrt((aux.x*aux.x)+(aux.y*aux.y));
		}

		for(int i = 1 ; i < (int)down.size() ; ++i)
		{
			point aux;

			aux = down[i-1] - down[i];

			resp += sqrt((aux.x*aux.x)+(aux.y*aux.y));
		}

		cout << setprecision(2) << fixed;

		cout << "Tera que comprar uma fita de tamanho ";
		cout << resp << ".\n";

		v.clear();
		up.clear();
		down.clear();
		resp = 0;
	}

	return 0;
}