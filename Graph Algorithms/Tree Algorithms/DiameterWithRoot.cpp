#include<iostream>
#include<vector>
#define MAX_NODES 100000
using namespace std;

vector< vector<int> > adjList(MAX_NODES, vector<int>());
int toLeaf[MAX_NODES];
int Diameter(int curr, int prev)
{
    if(adjList[curr].size()==1 && adjList[curr][0]==prev)
    {
        toLeaf[curr]=0;
        return 0;
    }
    int longest=-1, longer=-1, ans=0;
    for(int i=0; i<adjList[curr].size(); i++)
    {
        if(adjList[curr][i]!=prev)
        {
            ans=max(Diameter(adjList[curr][i], curr), ans);
            if(toLeaf[adjList[curr][i]]>longest)
            {
                longer=longest;
                longest=toLeaf[adjList[curr][i]];
            }
            else if(toLeaf[adjList[curr][i]]>longer)
            {
                longer=toLeaf[adjList[curr][i]];
            }
        }
    }
    toLeaf[curr]=longest+1;
    if(longer==-1)
        return max(ans, longest+1);
    else
        return max(ans, longest+longer+2);
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
    cout<<Diameter(1, -1)<<endl;
}