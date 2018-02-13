#include<iostream>
#include<vector>
#define MAX_NODES 100000
using namespace std;

vector< vector<int> > adjList(MAX_NODES, vector<int>());
int iniVal[MAX_NODES];
int firstEnc[MAX_NODES];
vector<int>treeTrav;
int segTree[2*MAX_NODES+10];
int nodes[MAX_NODES];
int countNodes(int curr, int prev)
{
    nodes[curr]=1;
    if(adjList[curr].size()==1 && adjList[curr][0]==prev)
    {
        return nodes[curr];
    }
    for(int i=0; i<adjList[curr].size(); i++)
    {
        if(adjList[curr][i]!=prev)
        {
            nodes[curr]+=countNodes(adjList[curr][i], curr);
        }
    }
    return nodes[curr];   
} 
void CreArr(int curr, int prev, int *cou)
{
    firstEnc[curr]=*cou;
    (*cou)++;
    treeTrav.push_back(curr);
    for(int i=0; i<adjList[curr].size(); i++)
        if(adjList[curr][i]!=prev)
            CreArr(adjList[curr][i], curr, cou);
}

void build(int s, int e, int cth)
{
    if(s==e)
    {
        segTree[cth]=iniVal[s];
        return;
    }
    int mid=(s+e)/2;
    build(s, mid, cth*2);
    build(mid+1, e, cth*2+1);
    segTree[cth]=segTree[cth*2]+segTree[cth*2+1];
}

void update(int s, int e, int n, int v, int cth)
{
    if(e<n || n<s)
        return;
    if(s==e)
    {
        segTree[cth]=v;
        return;
    }
    int mid=(s+e)/2;
    update(s, mid, n, v,cth*2);
    update(mid+1, e, n, v,cth*2+1);
    segTree[cth]=segTree[cth*2]+segTree[cth*2+1];
}

int query(int s, int e, int ters, int tere, int cth)
{
    if(ters<=s && e<=tere)
        return segTree[cth];
    else if(tere<s || e<ters)
        return 0;
    int mid=(s+e)/2;
    return query(s, mid,ters, tere,cth*2)+query(mid+1, e, ters, tere,cth*2+1);
}

int main()
{
    int n, m;
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        int x, y;
        cin>>x>>y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    int cou=0;
    CreArr(1, 0, &cou);
    for(int i=1; i<=n; i++)
        cin>>iniVal[firstEnc[i]];
    build(0, n-1, 1);
    countNodes(1, 0);
    int q;
    cin>>q;
    while(q--)
    {
        char type;
        int node;
        cin>>type>>node;
        if(type=='U')
        {
            int value;
            cin>>value;
            update(0, n-1, firstEnc[node], value, 1);
        }
        else if(type=='Q')
        {
            cout<<query(0,n-1,firstEnc[node],firstEnc[node]+nodes[node]-1,1)<<endl;
        }
    }
}