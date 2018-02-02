#include<iostream>
#include<vector>
#define MAX_NODES 100000
using namespace std;

vector< vector<int> > adjList(MAX_NODES, vector<int>());
int nodes[MAX_NODES];
int countNodes(int curr, int prev)
{
    nodes[curr]=1;
    if(adjList[curr].size()==1 && adjList[curr][0]==prev)
    {
        return nodes[curr];
    }
    for(int i=0; i<adjList[curr].size(); i++)
    {
        if(adjList[curr][i]!=prev)
        {
            nodes[curr]+=countNodes(adjList[curr][i], curr);
        }
    }
    return nodes[curr];   
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        int x, y;
        cin>>x>>y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    countNodes(0, -1);
    for(int i=0; i<n; i++)
    {
        cout<<"Subtree "<<i<<" has "<<nodes[i]<<" nodes\n";
    }
}