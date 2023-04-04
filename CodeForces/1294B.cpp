#include <bits/stdc++.h>

using namespace std;

struct point
{
	int x,y;

	bool operator< (point b)const
	{
		if(x != b.x)return x < b.x;
		return y < b.y;
	}

	point operator- (point b)const
	{
		point ans;
		ans.x = x - b.x;
		ans.y = y - b.y;
		return ans;
	}
};

bool resp = true;
int n,m;
vector<point> v,moves;

int main()
{
	cin >> n;

	for(int i = 1 ; i <= n ; ++i)
	{
		cin >> m;

		v.push_back({0,0});

		for(int j = 0 ; j < m ; ++j)
		{
			int a,b;
			cin >> a >> b;
			v.push_back({a,b});
		}

		sort(v.begin() , v.end());

		for(int j = 1 ; j <= m ; ++j)
		{
			point aux = v[j] - v[j-1];

			if(aux.x < 0 || aux.y < 0)
			{
				resp = false;
				break;
			}

			moves.push_back(aux);
		}

		if(resp)
		{
			cout << "YES\n";

			for(int j = 0 ; j < moves.size() ; ++j)
			{
				for(int k = 0 ; k < moves[j].x ; ++k)
				{
					cout << "R";
				}
				for(int k = 0 ; k < moves[j].y ; ++k)
				{
					cout << "U";
				}
			}

		}else
		{
			cout << "NO";
		}

		cout << "\n";


		v.clear();
		moves.clear();
		resp = true;
	}

	return 0;
}