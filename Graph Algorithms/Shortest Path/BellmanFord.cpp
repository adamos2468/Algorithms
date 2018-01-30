#include<iostream>
#include<vector>
#define INF 1000000007
#define MAX_NODES 100000
using namespace std;

struct edge{
    int weight;
    int node_a;
    int node_b;
};
int dist[MAX_NODES];
vector<edge> edgeList;
void resetDist(int n)
{
    for(int i=0; i<n; i++)
        dist[i]=INF;
}
bool bellmanFord(int startNode, int nodes, int edges)
{
    dist[startNode]=0;
    bool neg;
    for(int i=0; i<=nodes; i++)
    {
        neg=false;
        for(int j=0; j<edges; j++)
        {
            edge temp=edgeList[j];
            if(dist[temp.node_b]>dist[temp.node_a]+temp.weight)
            {
                neg=true;
                dist[temp.node_b]=dist[temp.node_a]+temp.weight;
            }
            if(dist[temp.node_a]>dist[temp.node_b]+temp.weight)
            {
                neg=true;
                dist[temp.node_a]=dist[temp.node_b]+temp.weight;
            }
        }
        if(!neg)
            break;
    }
    return neg;
}
int main()
{
    int n, m, start;
    cin>>n>>m>>start;
    for(int i=0; i<m; i++)
    {
        int a, b, w;
        cin>>a>>b>>w;
        edge temp; 
        temp.weight=w;
        temp.node_a=a;
        temp.node_b=b;
        edgeList.push_back(temp);
    }
    resetDist(n);
    bool NegativeCycle=bellmanFord(start, n, m);
    cout<<(NegativeCycle? "Has Negative Cycle":"It's Ok")<<endl;
}