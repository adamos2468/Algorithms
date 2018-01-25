#include<iostream>
#include<queue>
#include<vector>
#define MAX_NODES 100000

using namespace std;

queue <int> nextNodes;
vector< vector<int> > adjList(MAX_NODES, vector<int>()); 
bool visited[MAX_NODES];

void bfs(int s)
{
    visited[s]=true;
    nextNodes.push(s);
    while(!nextNodes.empty())
    {
        int nextNode=nextNodes.front();
        nextNodes.pop();
        for(int i=0; i<adjList[nextNode].size(); i++)
            if(!visited[adjList[nextNode][i]])
            {
                visited[adjList[nextNode][i]]=true;
                nextNodes.push(adjList[nextNode][i]);
            }
    }
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
    {
        if(!visited[i])
            bfs(i);
    }
}