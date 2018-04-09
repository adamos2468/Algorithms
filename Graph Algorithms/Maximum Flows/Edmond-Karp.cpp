#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#define MAX_NODES 5005
#define INF 1000000007
using namespace std;
vector< vector<int> > adjList(MAX_NODES, vector<int>());
queue<int>nextNodes;
int cap[MAX_NODES][MAX_NODES];
int fath[MAX_NODES];
int applyFlow(int curr, int fl)
{
    if(fath[curr]==curr)
        return fl;
    fl=applyFlow(fath[curr], min(fl, cap[fath[curr]][curr]));
    cap[fath[curr]][curr]-=fl;
    cap[curr][fath[curr]]+=fl;
    return fl;
}

int getFlow(int source, int sink)
{
    nextNodes.push(source);
    fath[source]=source;
    while(!nextNodes.empty())
    {
        int nextNode=nextNodes.front();
        nextNodes.pop();
        if(fath[sink]!=0)
            continue;
        for(int i=0; i<adjList[nextNode].size(); i++)
            if(fath[adjList[nextNode][i]]==0 && cap[nextNode][adjList[nextNode][i]]!=0)
            {
                nextNodes.push(adjList[nextNode][i]);
                fath[adjList[nextNode][i]]=nextNode;
            }
    }
    if(fath[sink]==0)
        return 0;
    int ans=applyFlow(sink, INF);
    return ans;
}

int EdmondKarp(int source, int sink, int nodes)
{
    int maxFlow=0, c=0;
    do{
        c=getFlow(source, sink);
        maxFlow+=c;
        memset(fath, 0, sizeof(fath));
    }while(c!=0);
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
    int maxFlow=EdmondKarp(source, sink, n);
    cout<<maxFlow<<endl;
}