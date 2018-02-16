#include<iostream>
#include<vector>
#define MAX_NODES 100000
#define MAX_POW 64
using namespace std;
vector< vector<int> > adjList(MAX_NODES, vector<int>());
vector< pair< pair<int, int>, int> > queries;
vector< vector<int> > whatPairs(MAX_NODES, vector<int>());
int fath[MAX_NODES];
int find(int x)
{
    while(x!=fath[x])
        x=fath[x];
    return x;
}
void unite(int a, int b)
{
    fath[find(a)]=fath[find(b)];
}
void LCATour(int curr, int prev)
{
    fath[curr]=curr;
    for(int i=0; i<whatPairs[curr].size(); i++)
    {
        int th=whatPairs[curr][i];
        int a=queries[th].first.first, b=queries[th].first.second;
        if(a==curr)
            swap(a, b);
        if(fath[a]!=0)
            queries[th].second=find(a);
    }
    for(int i=0; i<adjList[curr].size(); i++)
    {
        if(adjList[curr][i]!=prev)
        {
            LCATour(adjList[curr][i], curr);
            unite(adjList[curr][i], curr);
        }
    }
}
int main()
{
    int n, m, root, q;
    cin>>n>>root;
    for(int i=0; i<n-1; i++)
    {
        int x, y;
        cin>>x>>y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    cin>>q;
    for(int i=0; i<q; i++)
    {
        int x, y;
        cin>>x>>y;
        queries.push_back(make_pair(make_pair(x, y), 0));
        whatPairs[x].push_back(i);
        whatPairs[y].push_back(i);
    }
    LCATour(root, 0);
    for(int i=0; i<q; i++)
        cout<<queries[i].second<<endl;
}