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
        if(!visited[s])
            dfs(adjList[s][i]);
}
bool isConnected(int n)
{
    dfs(0);
    for(int i=0; i<n; i++)
        if(!visited[i])
            return false;
    return true;
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
    cout<<(isConnected(n) ? "It is Connected":"It is not Connected")<<endl;
}