#include<iostream>
#include<algorithm>
#define N 1000
using namespace std;

int pin[N];

bool binSearch(int s, int e, int num)
{
    if(s==e)
        return num==pin[s];
    int mid=(s+e)/2;
    if(num>pin[mid])
        return binSearch(mid+1, e, num);
    else
        return binSearch(0, mid, num);
}

int main()
{
    int n, x;
    cin>>n>>x;
    for(int i=0; i<n; i++)
        cin>>pin[i];
    sort(pin, pin+n);
    if(binSearch(0, n-1, x))
        cout<<"Found!!!"<<endl;
    else
        cout<<"Not found..."<<endl;
}