#include<bits/stdc++.h>
#define Y imag();
#define X real();
#define e 10e-9
using namespace std;

typedef complex<double> Point;

double crossProduct(Point a, Point b)
{
	return (conj(a)*b).Y;
}

int main()
{
	Point a, b;
	double x, y;
	cin>>x>>y;
	a={x, y};
	cin>>x>>y;
	b={x, y};
	double turn=crossProduct(a, b);
	if(turn<0)
		cout<<"Turns Right\n";
	else if(turn==0)
		cout<<"Continues Straight\n";
	else
		cout<<"Turns Left\n";
}
