#include<bits/stdc++.h>
#define X real()
#define Y imag()
using namespace std;

typedef complex<double> Point;

Point rotate(Point a, double r)
{
	return a*polar(1.0, r);
}

int main()
{
	double x, y, r;
	cin>>x>>y>>r;
	Point a={x, y};
	a=rotate(a, r);
}
