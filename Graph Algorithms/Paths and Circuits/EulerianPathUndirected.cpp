#include<iostream>
#include<vector>
#define MAX_NODES 100000
using namespace std;

vector< vector<int> > adjList(MAX_NODES, vector<int>());
int start, last;
int isEulerianPath(int nodes)
{
    int cou=0;
    for(int i=1; i<=nodes; i++)
    {
        if(adjList[i].size()%2==0 && cou==0)
        {
            cou++;
            start=i;
        }
        else if(adjList[i].size()%2==0 && cou==1)
        {
            cou++;
            last=i;
        }
        else if(adjList[i].size()%2==0)
            return 1;
    }
    return cou;
}
int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    
    int ans=isEulerianPath(n);
    if(ans==1)
        cout<<"It is not Eulerian Path\n";
    else if(ans==2)
        cout<<"It has Eulerian Path from "<<start<<" "<<last<<endl;
    else
        cout<<"It is Eulerian Circuit\n";

}