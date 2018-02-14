#include<iostream>
#include<vector>
#define MAX_NODES 100000
#define MAX_POW 64
using namespace std;

vector< vector<int> > adjList(MAX_NODES, vector<int>());
vector< vector< pair<int, int> > > sparse;
vector< pair<int, int> > treeTrav;
int firstEnc[MAX_NODES];
int depth;
void traverse(int curr, int prev)
{
    depth++;
    firstEnc[curr]=treeTrav.size();
    treeTrav.push_back(make_pair(depth, curr));
    sparse.push_back(vector< pair<int, int> >(MAX_POW, make_pair(0,0)));
    if(adjList[curr].size()==1 && adjList[curr][0]==prev)
    {   
        depth--; 
        return;
    }
    for(int i=0; i<adjList[curr].size(); i++)
        if(adjList[curr][i]!=prev)
        {
            traverse(adjList[curr][i], curr);
            treeTrav.push_back(make_pair(depth, curr));
            sparse.push_back(vector< pair<int, int> >(MAX_POW, make_pair(0,0)));
        }
    depth--;    
}
void miniPre()
{
    for(int i=0; i<sparse.size(); i++)
    {
        for(int j=0; i-(1<<j)>=-1; j++)//-1 because is 0 based
        {
            if(j==0)
                sparse[i][j]=treeTrav[i];
            else
                sparse[i][j]=min(sparse[i][j-1], sparse[i-(1<<(j-1))][j-1]);
        }
    }
}
void prePro(int root)
{
    traverse(root, 0);
    miniPre();
}
int larPow(int x)
{
    int p=0;
    while(x>0)
    {
        p++;
        x>>=1;
    }
    return p;
}
int LCA(int a, int b)
{
    if(a==b)
        return a;
    a=firstEnc[a];
    b=firstEnc[b];
    if(a>b)
        swap(a, b);
    int p=larPow(b-a+1)-1;
    int w=1<<p;
    return min(sparse[a+w][p], sparse[b][p]).second;   
}
int main()
{
    int n, m, root;
    cin>>n>>root;
    for(int i=0; i<n-1; i++)
    {
        int x, y;
        cin>>x>>y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    prePro(root);
    int a, b;
    cin>>a>>b;
    cout<<LCA(a, b)<<endl;
}