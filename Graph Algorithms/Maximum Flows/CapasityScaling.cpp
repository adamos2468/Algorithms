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
int getFlow(int curr, int sink, int fl, int threshold)
{
    visited[curr]=true;
    if(curr==sink)
        return fl;
    for(int i=0; i<adjList[curr].size(); i++)
    {
        if(!visited[adjList[curr][i]] && cap[curr][adjList[curr][i]]>=threshold)
        {
            int c=getFlow(adjList[curr][i], sink, min(fl, cap[curr][adjList[curr][i]]), threshold);
            if(visited[sink])
            {
                cap[curr][adjList[curr][i]]-=c;
                cap[adjList[curr][i]][curr]+=c;
                return c;
            }
        }
    }
}

int CapasityScaling(int source, int sink, int nodes, int threshold)
{
    if(source==sink)
        return 0;
    int maxFlow=0, c=0;
    do{
        c=getFlow(source, sink, INF, threshold);
        maxFlow+=c;
        for(int i=0; i<=nodes; i++)
            visited[i]=false;
        if(c==0)
            threshold>>=1;
    }while(threshold!=0);
    return maxFlow;
}

int main()
{
    int C=0;
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
        if(x==source || y==source)
            C+=w;
    }
    int maxFlow=CapasityScaling(source, sink, n, C);
    cout<<maxFlow<<endl;
}