#include<iostream>
#define MAX_NODES 100000
#define MAX_POW 64
using namespace std;
int succ[MAX_NODES];
int hops[MAX_POW][MAX_NODES];
void prepro(int nodes)
{
    for(int i=0; i<MAX_POW; i++)
    {
        for(int j=1; j<=nodes; j++)
        {
            if(i==0)
                hops[i][j]=succ[j];
            else
                hops[i][j]=hops[i-1][hops[i-1][j]];
        }
    }
}
int getNode(int start, int dist)
{
    int ans=start;
    int many=0;
    while(dist>0)
    {
        if(dist&1)
            ans=hops[many][ans];
        many+=1;
        dist>>=1;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>succ[i];
    prepro(n);
    int s, h;
    cin>>s>>h;
    cout<<getNode(s, h)<<endl;
}