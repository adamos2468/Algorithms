#include<iostream>
#include<vector>
#include<queue>
#define MAX_NODES 100000
using namespace std;

vector< vector< pair<int, int> > > adjList(MAX_NODES, vector< pair<int, int> >());
priority_queue< pair<int, int> >nextNodes;
bool visited[MAX_NODES];
void addNode(int n)
{
    visited[n]=true;
    for(int i=0; i<adjList[n].size(); i++)
        nextNodes.push(make_pair(-adjList[n][i].second, adjList[n][i].first));
}
int main()
{
    long long mst=0;
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int x, y, w;
        cin>>x>>y>>w;
        adjList[x].push_back(make_pair(y, w));
        adjList[y].push_back(make_pair(x, w));
    }
    addNode(0);
    while(!nextNodes.empty())
    {
        if(visited[nextNodes.top().second])
            nextNodes.pop();
        else{
            mst-=nextNodes.top().first;
            int next=nextNodes.top().second;
            nextNodes.pop();
            addNode(next);
        }
    }
    cout<<mst<<endl;
}