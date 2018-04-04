#include<iostream>
#include<vector>
#define MAX_NODES 100000
using namespace std;
vector< vector<int> > adjList(MAX_NODES, vector<int>());
vector< vector<int> > centroidTree(MAX_NODES, vector<int>());
int centroidRoot;
int nodes[MAX_NODES];
int countNodes(int curr, int prev)
{
    if(nodes[curr]==-1)
        return 0;
    nodes[curr]=1;
    if(adjList[curr].size()==1 && adjList[curr][0]==prev)
    {
        return nodes[curr];
    }
    for(int i=0; i<adjList[curr].size(); i++)
        if(adjList[curr][i]!=prev)
            nodes[curr]+=countNodes(adjList[curr][i], curr);
    return nodes[curr];   
}
int Centroid(int curr, int prev, int n)
{
    for(int i=0; i<adjList[curr].size(); i++)
        if(nodes[adjList[curr][i]]>n/2 && adjList[curr][i]!=prev)
            return Centroid(adjList[curr][i], curr, n);
    return curr;
}
void create(int root, int prev)
{
    countNodes(root, prev);
    int c=Centroid(root, 0, nodes[root]);
    if(prev!=0)
    {
        centroidTree[prev].push_back(c);
        centroidTree[c].push_back(prev);
    }
    else
        centroidRoot=c;
    if(nodes[root]!=1)
    {
        nodes[c]=-1;
        for(int i=0; i<adjList[c].size(); i++)
            if(nodes[adjList[c][i]]!=-1)
                create(adjList[c][i], c);
    }
    nodes[c]=-1;
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
    create(1, 0);
    for(int i=1; i<=n; i++)
    {
        cout<<i<<": ";
        for(int j=0; j<centroidTree[i].size(); j++)
        {
            cout<<centroidTree[i][j]<<" ";
        }
        cout<<endl;
    }
}