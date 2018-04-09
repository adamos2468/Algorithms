#include<iostream>
#include<vector>
#include<queue>
#define MAX_NODES 5005
#define INF 1000000007
using namespace std;
vector< vector<int> > adjList(MAX_NODES, vector<int>());
queue<int>nextNodes;
int cap[MAX_NODES][MAX_NODES];
bool added[MAX_NODES][MAX_NODES];
int fath[MAX_NODES];
bool visited[MAX_NODES];
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
    visited[source]=true;
    nextNodes.push(source);
    fath[source]=source;
    while(!nextNodes.empty())
    {
        int nextNode=nextNodes.front();
        nextNodes.pop();
        if(visited[sink])
            continue;
        for(int i=0; i<adjList[nextNode].size(); i++)
            if(!visited[adjList[nextNode][i]] && cap[nextNode][adjList[nextNode][i]]!=0)
            {
                visited[adjList[nextNode][i]]=true;
                nextNodes.push(adjList[nextNode][i]);
                fath[adjList[nextNode][i]]=nextNode;
            }
    }
    if(!visited[sink])
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
        for(int i=0; i<=nodes; i++)
            visited[i]=false;
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
        if(!added[x][y]){
            adjList[x].push_back(y);
            adjList[y].push_back(x);
            added[x][y]=added[y][x]=true;
        }
        cap[x][y]+=w;
    }
    int maxFlow=EdmondKarp(source, sink, n);
    cout<<maxFlow<<endl;
}