#include<iostream>
#include<vector>
#define MAX_NODES 100000
using namespace std;

vector< vector<int> > adjList(MAX_NODES, vector<int>());
pair<int, int> maxLength[2][MAX_NODES];
int maxPath[MAX_NODES];
pair<int, int> toChildren(int curr, int prev)
{
    if(adjList[curr].size()==1 && adjList[curr][0]==prev)
    {
        maxLength[0][curr]=make_pair(0, curr);
        maxLength[1][curr]=make_pair(-1, -1);
        return maxLength[0][curr];
    }
    maxLength[0][curr]=maxLength[1][curr]=make_pair(-1, -1);
    for(int i=0; i<adjList[curr].size(); i++)
    {
        if(adjList[curr][i]!=prev)
        {
            pair<int, int> temp=toChildren(adjList[curr][i], curr);
            temp.first++;
            if(temp.first>maxLength[0][curr].first)
            {
                maxLength[1][curr]=maxLength[0][curr];
                maxLength[0][curr]=make_pair(temp.first, adjList[curr][i]);
            }
            else if(temp.first>maxLength[1][curr].first)
            {
                maxLength[1][curr]=make_pair(temp.first, adjList[curr][i]);
            }
        }
    }
    return maxLength[0][curr];   
}
void toFather(int curr, int prev)
{
    if(prev!=-1)
    {
        if(maxLength[0][prev].first+1>maxLength[0][curr].first && maxLength[0][prev].second!=curr)
            maxLength[0][curr]=make_pair(maxLength[0][prev].first+1, prev);
        else if(maxLength[1][prev].first+1>maxLength[0][curr].first)
            maxLength[0][curr]=make_pair(maxLength[1][prev].first+1, prev);
    }
    maxPath[curr]=maxLength[0][curr].first;
    if(adjList[curr].size()==1 && adjList[curr][0]==prev)
        return;
    for(int i=0; i<adjList[curr].size(); i++)
    {
        if(adjList[curr][i]!=prev)
        {
            toFather(adjList[curr][i], curr);
        }
    }
    
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
    int root=0;
    toChildren(root, -1);
    toFather(root, -1);
    for(int i=0; i<n; i++)
    {
        cout<<"Length of Longest Path from "<<i<<" is "<<maxPath[i]<<"\n";
    }
}