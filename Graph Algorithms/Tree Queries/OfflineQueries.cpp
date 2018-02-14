#include<iostream>
#include<vector>
#include<map>
#define MAX_NODES 100001
using namespace std;

vector< vector<int> > adjList(MAX_NODES, vector<int>());
map<int, int> dedo[MAX_NODES];
int pin[MAX_NODES];
void merge(map<int, int>& a, map<int, int> b)
{
    if(a.size()<b.size())
        swap(a, b);
    map<int, int>::iterator i;
    for(i=b.begin(); i!=b.end(); i++)
        if(a.find(i->first)!=a.end())
            a[i->first]+=i->second;
        else
            a[i->first]=i->second;
}
void prePro(int curr, int prev)
{
    cout<<curr<<endl;
    dedo[curr][pin[curr]]=1;
    for(int i=0; i<adjList[curr].size(); i++)
        if(adjList[curr][i]!=prev){
            prePro(adjList[curr][i], curr);
            merge(dedo[curr], dedo[adjList[curr][i]]);
        }
}
int main()
{
    int n, root;
    cin>>n>>root;
    for(int i=0; i<n-1; i++)
    {
        int x, y;
        cin>>x>>y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    for(int i=1; i<=n; i++)
        cin>>pin[i];
    prePro(root, 0);
    int node, val;
    cin>>node>>val;
    cout<<dedo[node][val]<<endl;
}