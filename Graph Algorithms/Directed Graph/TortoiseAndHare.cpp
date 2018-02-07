#include<iostream>
#define MAX_NODES 100000
#define MAX_POW 64
using namespace std;
int succ[MAX_NODES];
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>succ[i];
    int x;
    cin>>x;
    int a=succ[x];
    int b=succ[succ[x]];
    while(a!=b)
    {
        a=succ[a];
        b=succ[succ[b]];
    }
    a=x;
    while(a!=b)
    {
        a=succ[a];
        b=succ[b];
    }
    int first=a;
    b=succ[a];
    int length=1;
    while(a!=b)
    {
        b=succ[b];
        length++;
    }
    cout<<"The cycle starts at Node "<<first<<" and has length "<<length<<endl;
}