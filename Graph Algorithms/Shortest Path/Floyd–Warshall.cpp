#include<iostream>
#define MAX_NODES 1000
#define INF 1000000007
using namespace std;
int adjMatrix[MAX_NODES][MAX_NODES];
void reset(int nodes)
{
    for(int i=0; i<nodes; i++)
        for(int j=0; j<nodes; j++)
            adjMatrix[i][j]=(i==j ? 0:INF);
}
void floyd_warshal(int nodes)
{
    for(int k=0; k<nodes; k++)
        for(int i=0; i<nodes; i++)
            for(int j=0; j<nodes; j++)
                adjMatrix[i][j]=min(adjMatrix[i][j], adjMatrix[i][k]+adjMatrix[k][j]);
}
int main()
{
    int n, m;
    cin>>n>>m;
    reset(n);
    for(int i=0; i<m; i++)
    {
        int x, y, w;
        cin>>x>>y>>w;
        adjMatrix[x][y]=w;
        adjMatrix[y][x]=w;
    }
    floyd_warshal(n);
}