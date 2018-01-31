#include<iostream>
#include<vector>
#include<queue>
#define MAX_NODES 100000
#define INF 1000000007
using namespace std;

vector< vector< pair<int, int> > > adjList(MAX_NODES, vector< pair<int, int> >()); 
priority_queue< pair<int, int> > selector;
int dist[MAX_NODES];
bool visited[MAX_NODES];
void reset(int n)
{
    for(int i=0; i<n; i++){
        dist[i]=INF;
        visited[i]=INF;
    }
}
void dijkstra(int start, int nodes)
{
    dist[start]=0;
    selector.push(make_pair(0, start));
    while(!selector.empty())
    {
        pair<int, int> temp_pair=selector.top();
        selector.pop();
        int curr=temp_pair.second;
        if(visited[curr])
            continue;
        visited[curr]=true;
        for(int i=0; i<adjList[curr].size(); i++)
        {
            if(dist[adjList[curr][i].first]>dist[curr]+adjList[curr][i].second)
            {
                dist[adjList[curr][i].first]=dist[curr]+adjList[curr][i].second;
                selector.push(make_pair(-dist[adjList[curr][i].first], adjList[curr][i].first));
            }
        }
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
    dijkstra(start, n);
    for(int i=0; i<n; i++)
    {
        cout<<"Shortest Path from "<<start<<" to "<<i<<" is "<<dist[i]<<endl;
    }
}
