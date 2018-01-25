#include<iostream>
#include<vector>
#define MAX_NODES 100000
using namespace std;
vector< vector<int> > adjList(MAX_NODES, vector<int>()); 
bool visited[MAX_NODES];
void dfs(int s)
{
    visited[s]=true;
    for(int i=0; i<adjList[s].size(); i++)
        if(!visited[adjList[s][i]])
            dfs(adjList[s][i]);
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
            dfs(i);
}