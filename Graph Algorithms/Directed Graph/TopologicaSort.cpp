#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define MAX_NODES 100000
using namespace std;

vector< vector<int> > adjList(MAX_NODES, vector<int>());
int visited[MAX_NODES];
stack<int>sorting;
bool topSort(int n)
{
    bool ans=true;
    visited[n]=1;
    for(int i=0; i<adjList[n].size(); i++)
        if(visited[adjList[n][i]]==1)
            return false;
        else if(visited[adjList[n][i]]==0)
            ans&=topSort(adjList[n][i]);
    visited[n]=2;
    sorting.push(n);
    return ans;
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
    }
    for(int i=n; i>=1; i--)
    {
        if(visited[i]==0 && !topSort(i))
        {
            cout<<"There is a Cycle!\n";
            return 0;
        }
    }
    while(!sorting.empty())
    {
        cout<<sorting.top()<<" ";
        sorting.pop();
    }
    cout<<endl;
}