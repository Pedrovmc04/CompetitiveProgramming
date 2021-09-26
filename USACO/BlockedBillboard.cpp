#include <bits/stdc++.h>

using namespace std;

struct point
{
	int x,y;
};

int intersect(point a, point b , point c , point d){

	int xOverlap = max(0,min(b.x,d.x)-max(a.x,c.x));

	int yOverlap = max(0,min(b.y,d.y)-max(a.y,c.y));

	return xOverlap*yOverlap;

}

int ans;
point outdoor1[5],outdoor2[5],caminhao[5];


int main()
{
	cin >> outdoor1[1].x >> outdoor1[1].y >> outdoor1[3].x >> outdoor1[3].y;
	cin >> outdoor2[1].x >> outdoor2[1].y >> outdoor2[3].x >> outdoor2[3].y;
	cin >> caminhao[1].x >> caminhao[1].y >> caminhao[3].x >> caminhao[3].y;

	ans += (outdoor1[1].x - outdoor1[3].x) * (outdoor1[1].y - outdoor1[3].y);
	ans += (outdoor2[1].x - outdoor2[3].x) * (outdoor2[1].y - outdoor2[3].y);

	ans -= (intersect(outdoor1[1],outdoor1[3],caminhao[1],caminhao[3]));
	ans -= (intersect(outdoor2[1],outdoor2[3],caminhao[1],caminhao[3]));

	
	cout << ans << "\n";


	return 0;
}