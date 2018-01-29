#include<iostream>
#include<vector>
#include<queue>
#define INF 1000000000
#define MAX_NODES 100000
using namespace std;
struct edge{
    int dest;
    int weight;
};
vector< vector<edge> > adjList(MAX_NODES, vector<edge>()); 
int dist[MAX_NODES];
queue<int> nextNodes[2];
void resetDist(int n)
{
    for(int i=0; i<n; i++)
        dist[i]=INF;
}
bool SPFA(int startNode, int nodes)
{
    dist[startNode]=0;
    bool neg;
    nextNodes[0].push(startNode);
    int t=0, p=1;
    for(int i=0; i<=nodes; i++)
    {
        neg=false;
        while(!nextNodes[t].empty())
        {
            int curr=nextNodes[t].front();
            nextNodes[t].pop();
            for(int j=0; j<adjList[curr].size(); j++)
            {
                int a=curr, b=adjList[curr][j].dest, w=adjList[curr][j].weight;
                if(dist[b]>dist[a]+w)
                {
                    neg=true;
                    dist[b]=dist[a]+w;
                    nextNodes[p].push(b);
                }
            }
        }
        if(!neg)
            break;
        t=1-t;
        p=1-p;
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
        temp.dest=b;
        temp.weight=w;
        adjList[a].push_back(temp);
        temp.dest=a;
        adjList[b].push_back(temp);
    }
    resetDist(n);
    bool negative=SPFA(start, n);
    cout<<(negative?"Negative Cycle Found!":"It's Ok")<<endl;
}