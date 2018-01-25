#include<iostream>
#include<vector>
#define MAX_NODES 100000
using namespace std;
vector< vector<int> > adjList(MAX_NODES, vector<int>()); 
bool visited[MAX_NODES];
int color[MAX_NODES];
bool bipartiteCheck(int s, int e, int c)
{
    visited[s]=c;
    if(c==1) c=2;
    else if(c==2) c==1;
    bool ans=true;
    for(int i=0; i<adjList[s].size(); i++)
        if(!visited[adjList[s][i]])
            ans&=bipartiteCheck(adjList[s][i], s, c);
        else if(color[adjList[s][i]]!=c)
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
    bool flag=true;
    for(int i=0; i<n; i++)
        if(!visited[i])
            flag&=bipartiteCheck(i, -1, 1);
    cout<<(flag ? "Is Bipartite":"Is not Bipartite")<<endl;
}