#include<iostream>
#include<vector>
#define MAX_NODES 100000
#define MAX_POW 64
using namespace std;

vector< vector<int> > adjList(MAX_NODES, vector<int>());
int hops[MAX_POW][MAX_NODES];
void prePro(int curr, int prev)
{
    hops[0][curr]=prev;
    for(int i=1; i<MAX_POW; i++)
        hops[i][curr]=hops[i-1][hops[i-1][curr]];
    for(int i=0; i<adjList[curr].size(); i++)
        if(adjList[curr][i]!=prev)
            prePro(adjList[curr][i], curr);
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
    int n, m, root;
    cin>>n>>m>>root;
    for(int i=0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    prePro(root, 0);
    int node, k;
    cin>>node>>k;
    cout<<getNode(node, k)<<endl;
}