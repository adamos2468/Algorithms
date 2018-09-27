#include<bits/stdc++.h>
#define Y imag();
#define X real();
#define e 10e-9
using namespace std;

typedef complex<long double> Point;

long double angle(Point a, Point b)
{
    return arg(b-a);
}

long double angle(Point a)
{
    return arg(a);
}

long double radTodegrees(double r)
{
    return (180.0*r)/M_PI;
}
int main()
{
    Point a, b;
    double x, y;
    cin>>x>>y;
    a={x, y};
    cin>>x>>y;
    b={x,y};
    cout<<angle(a, b)<<endl;
}