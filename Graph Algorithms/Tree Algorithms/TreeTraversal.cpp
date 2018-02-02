#include<iostream>
#include<vector>
#define MAX_NODES 100000
using namespace std;

vector< vector<int> > adjList(MAX_NODES, vector<int>());

void trip(int curr, int prev)
{
    for(int i=0; i<adjList[curr].size(); i++)
        if(adjList[curr][i]!=prev)
            trip(adjList[curr][i], curr);
}

int main()
{
    int n;
    for(int i=0; i<n-1; i++)
    {
        int x, y;
        cin>>x>>y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    trip(0, -1);
}