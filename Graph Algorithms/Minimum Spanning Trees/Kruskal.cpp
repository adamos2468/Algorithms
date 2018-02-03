#include<iostream>
#include<vector>
#include<algorithm>
#define MAX_NODES 100000
using namespace std;

vector<pair< int,pair<int, int> > > edgeList;
int fath[MAX_NODES], scale[MAX_NODES];
void reset(int nodes)
{
    for(int i=0; i<nodes; i++)
    {
        fath[i]=i;
        scale[i]=1;
    }
}
int find(int x)
{
    while(x!=fath[x])
        x=fath[x];
    return x;
}
bool same(int a, int b)
{
    return find(a)==find(b);
}
void unite(int a, int b)
{
    a=find(a);
    b=find(b);
    if(scale[a]<scale[b]) 
        swap(a, b);
    scale[a]+=scale[b];
    fath[b]=a;
}
int main()
{
    long long mst=0;
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int x, y, z;
        cin>>x>>y>>z;
        edgeList.push_back(make_pair(z, make_pair(x, y)));
    }
    sort(edgeList.begin(), edgeList.end());
    reset(n);
    for(int i=0; i<m; i++)
    {
        int a=edgeList[i].second.first;
        int b=edgeList[i].second.second;
        if(!same(a,b))
        {
            mst+=edgeList[i].first;
            unite(a, b);
        }
    }
    cout<<mst<<endl;
}