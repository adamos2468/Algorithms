#include<bits/stdc++.h>
#define Y imag()
#define X real()
#define E 10e-9
using namespace std;

typedef complex<double> Point;
typedef pair<Point, Point> Line;

double crossProduct(Point a, Point b)
{
	return (conj(a)*b).Y;
}

double ccw(Line a, Point p)
{
    return crossProduct(p-a.first, p-a.second);
}

int main()
{
    Line l;
    Point p;
    double x, y;
    cin>>x>>y;
    l.first={x,y};
    cin>>x>>y;
    l.second={x,y};
    cin>>x>>y;
    p={x,y};
    double loc=ccw(l, p);
    if(loc>0)
        cout<<"Point is Left\n";
    else if(abs(loc)<E)
        cout<<"Point is on Line\n";
    else
        cout<<"Point is Right\n";
}
