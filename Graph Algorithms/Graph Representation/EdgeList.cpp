#include<iostream>
#include<vector>
#define MAX_NODES 100000
using namespace std;

struct Edge{
    int node_A, node_B, weight;
};
vector<Edge> edgeList;

int main()
{
    int n, m;
    for(int i=0; i<m; i++)
    {
        int x, y, w;
        cin>>x>>y>>w;
        Edge temp;
        temp.node_A=x;
        temp.node_B=y;
        temp.weight=w;
        edgeList.push_back(temp);
    }
}