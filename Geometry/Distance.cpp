#include<bits/stdc++.h>
#define Y imag();
#define X real();
#define e 10e-9
using namespace std;

typedef complex<long double> Point;

long double dist(Point a, Point b)
{
    return abs(b-a);
}

int main()
{
    Point a, b;
    double x, y;
    cin>>x>>y;
    a={x, y};
    cin>>x>>y;
    b={x,y};
    cout<<dist(a, b)<<endl;
}