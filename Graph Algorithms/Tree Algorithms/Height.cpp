#include<iostream>
#include<vector>
#define MAX_NODES 100000
using namespace std;

vector< vector<int> > adjList(MAX_NODES, vector<int>());
int height[MAX_NODES];
int GetHeight(int curr, int prev)
{
    if(adjList[curr].size()==1 && adjList[curr][0]==prev)
    {
        height[curr]=0;
        return height[curr];
    }
    for(int i=0; i<adjList[curr].size(); i++)
    {
        if(adjList[curr][i]!=prev)
        {
            height[curr]=max(GetHeight(adjList[curr][i], curr)+1, height[curr]);
        }
    }
    return height[curr];   
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
    GetHeight(0, -1);
    for(int i=0; i<n; i++)
    {
        cout<<"Height of "<<i<<" is "<<height[i]<<"\n";
    }
}