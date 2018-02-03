#include<iostream>
#include<vector>
#define MAX_NODES 100000
using namespace std;

vector< pair<int, pair<int, int> > > edgeList;

int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int x, y, w;
        cin>>x>>y>>w;
        edgeList.push_back(make_pair(w, make_pair(x, y)));
    }
}