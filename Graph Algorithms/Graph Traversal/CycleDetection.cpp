#include<iostream>
#include<vector>
#define MAX_NODES 100000
using namespace std;
vector< vector<int> > adjList(MAX_NODES, vector<int>()); 
int visited[MAX_NODES];
bool cycle(int s, int e)
{
    bool ans=false;
    visited[s]=1;
    for(int i=0; i<adjList[s].size(); i++)
        if(visited[adjList[s][i]]==0)
            ans|=cycle(adjList[s][i], s);
        else if(visited[adjList[s][i]]==1 && adjList[s][i]!=e)
            ans=true;
    visited[s]=2;
    return ans;
}
int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    for(int i=0; i<n; i++)
        if(!visited[i])
            cycle(i, -1);
}