#include<iostream>
#define MAX_NODES 100000
using namespace std;

bool adjMatrix[MAX_NODES][MAX_NODES];

int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        adjMatrix[x][y]=true;
        adjMatrix[y][x]=true;
    }
}