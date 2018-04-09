#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<stdio.h>
#define MAX_NODES 5005
#define INF 1000000007
using namespace std;
vector< vector<int> > adjList(MAX_NODES, vector<int>());
queue<int>nextNodes;
int cap[MAX_NODES][MAX_NODES];
int level[MAX_NODES];
bool BFS(const int source, const int sink)
{
    level[source]=1;
    nextNodes.push(source);
    while(!nextNodes.empty())
    {
        int curr=nextNodes.front();
        nextNodes.pop();
        if(level[sink]!=0)
            continue;
        for(int i=0; i<adjList[curr].size(); i++)
        {
            if(cap[curr][adjList[curr][i]]>0){
                if(level[adjList[curr][i]]==0)
                {
                    level[adjList[curr][i]]=level[curr]+1;
                    nextNodes.push(adjList[curr][i]);
                }
            }
        }
    }
    return level[sink]!=0;
}

int getFlow(int curr, const int sink, int fl)
{
    if(curr==sink)
        return fl;
    for(int i=0; i<adjList[curr].size(); i++)
    {
        if(cap[curr][adjList[curr][i]]!=0 && level[curr]+1==level[adjList[curr][i]])
        {
            int c=getFlow(adjList[curr][i], sink, min(fl, cap[curr][adjList[curr][i]]));
            if(c>0)
            {
                cap[curr][adjList[curr][i]]-=c;
                cap[adjList[curr][i]][curr]+=c;
                return c;
            }
        }
    }
    return 0;
}
int Dinic(const int source, const int sink, const int nodes)
{
    int maxFlow=0, c=0;
    while(BFS(source, sink))
    {
        do{
            c=getFlow(source, sink, INF);
            maxFlow+=c;
        }while(c!=0);
        memset(level, 0, sizeof(level));
    }
    return maxFlow;
}

int main()
{
    int n, m, source, sink;
    cin>>n>>m;
    source=1; sink=n;
    for(int i=0; i<m; i++)
    {
        int x, y, w;
        cin>>x>>y>>w;
        if(cap[x][y]==0 && cap[y][x]==0){
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }
        cap[x][y]+=w;
    }
    int maxFlow=Dinic(source, sink, n);
    cout<<maxFlow<<endl;
}