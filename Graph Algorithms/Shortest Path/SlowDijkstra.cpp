#include<iostream>
#include<vector>
#define MAX_NODES 100000
#define INF 1000000007
using namespace std;

vector< vector< pair<int, int> > > adjList(MAX_NODES, vector< pair<int, int> >()); 
int dist[MAX_NODES];
bool visited[MAX_NODES];
void reset(int n)
{
    for(int i=0; i<=n; i++){
        dist[i]=INF;
        visited[i]=0;
    }
}
void dijkstra(int start, int nodes)
{
    dist[start]=0;
    int curr=start;
    for(int t=0; t<nodes-1; t++)
    {
        visited[curr]=true;
        for(int i=0; i<adjList[curr].size(); i++)
        {
            dist[adjList[curr][i].first]=min(dist[adjList[curr][i].first], dist[curr]+adjList[curr][i].second);
        }
        int tempc=curr;
        int temp=dist[curr];
        dist[curr]=INF;
        for(int i=1; i<=nodes; i++)
        {
            if(!visited[i] && dist[i]<dist[curr])
            {
                curr=i;
            }
        }
        dist[tempc]=temp;
    }
}
int main()
{
    int n, m, start;
    cin>>n>>m>>start;
    for(int i=0; i<m; i++)
    {
        int x, y, w;
        cin>>x>>y>>w;
        adjList[x].push_back(make_pair(y, w));
        adjList[y].push_back(make_pair(x, w));
    }
    reset(n);
    dijkstra(start, n);
    for(int i=1; i<=n; i++)
    {
        cout<<"Shortest Path from "<<start<<" to "<<i<<" is "<<dist[i]<<endl;
    }
}