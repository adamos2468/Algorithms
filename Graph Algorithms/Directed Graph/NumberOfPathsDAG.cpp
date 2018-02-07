#include<iostream>
#include<vector>
#include<stdio.h>
#define MAX_NODES 100001
#define MOD 1000000007

using namespace std;

vector< vector<int> > adjList(MAX_NODES, vector<int>());
long long paths[MAX_NODES];
void reset(int nodes)
{
    for(int i=0; i<=MAX_NODES; i++)
    {
        adjList[i].clear();
        paths[i]=-1;
    }
}
long long getPaths(int s, int e)
{
    if(s==e)
        return 1;
    if(paths[s]!=-1)
        return paths[s];
    long long ans=0;
    for(int i=0; i<adjList[s].size(); i++){
        ans+=getPaths(adjList[s][i], e);
        ans%=MOD;
    }
    paths[s]=ans;
    return paths[s];
}
int main()
{
    int n, m, s, e;
    reset(n);
    cin>>n>>m>>s>>e;
    for(int i=0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        adjList[x].push_back(y);
    }
    cout<<getPaths(s, e)<<endl;
}