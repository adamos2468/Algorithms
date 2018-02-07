#include<iostream>
#include<vector>
#include<stack>
#define MAX_NODES 100000
using namespace std;

vector< vector<int> > strList(MAX_NODES, vector<int>());
vector< vector<int> > revList(MAX_NODES, vector<int>());
bool strVis[MAX_NODES], revVis[MAX_NODES];
stack<int> order;
void dfs1(int s)
{
    strVis[s]=true;
    for(int i=0; i<strList[s].size(); i++)
        if(!strVis[strList[s][i]])
            dfs1(strList[s][i]);
    order.push(s);
}
void dfs2(int s)
{
    cout<<s<<" ";
    revVis[s]=true;
    for(int i=0; i<revList[s].size(); i++)
        if(!revVis[revList[s][i]])
            dfs2(revList[s][i]);
}
int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        strList[x].push_back(y);
        revList[y].push_back(x);
    }
    for(int i=1; i<=n; i++)
        if(!strVis[i])
            dfs1(i);
    while(!order.empty()){
        int node=order.top();
        order.pop();
        if(!revVis[node]){
            cout<<"Component: ";
            dfs2(node);
            cout<<endl;
        }
    }
}