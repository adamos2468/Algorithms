#include<iostream>
#include<vector>
#define MAX_NODES 100000
using namespace std;

vector< vector<int> > adjList(MAX_NODES, vector<int>());
pair<int, int> FarAway(int curr, int prev)
{
    pair<int, int> ans;
    if(adjList[curr].size()==1 && adjList[curr][0]==prev)
    {
        ans=make_pair(0, curr);
        return ans;
    }
    for(int i=0; i<adjList[curr].size(); i++)
    {
        if(adjList[curr][i]!=prev)
        {
            pair<int, int> temp=FarAway(adjList[curr][i], curr);
            temp.first++;
            ans=max(temp, ans);
        }
    }
    return ans;   
}
int Diameter()
{
    pair<int, int> temp=FarAway(1, -1);
    return FarAway(temp.second, -1).first;
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
    cout<<Diameter()<<endl;
}