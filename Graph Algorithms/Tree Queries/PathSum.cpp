#include<iostream>
#include<vector>
#define MAX_NODES 100000
using namespace std;

struct segNode{
    int val;
    int lazy;
};

vector< vector<int> > adjList(MAX_NODES, vector<int>());
int PathVal[MAX_NODES];
int firstEnc[MAX_NODES];
vector<int>treeTrav;
segNode segTree[2*MAX_NODES+10];
int nodes[MAX_NODES];
void CreArr(int curr, int prev, int *cou)
{
    firstEnc[curr]=*cou;
    (*cou)++;
    treeTrav.push_back(curr);
    for(int i=0; i<adjList[curr].size(); i++)
        if(adjList[curr][i]!=prev)
            CreArr(adjList[curr][i], curr, cou);
}
int countNodesAndPath(int curr, int prev)
{
    if(prev!=0)
    PathVal[firstEnc[curr]]+=PathVal[firstEnc[prev]];//Path count
    //Node count
    nodes[curr]=1;
    if(adjList[curr].size()==1 && adjList[curr][0]==prev)
        return nodes[curr];
    for(int i=0; i<adjList[curr].size(); i++)
        if(adjList[curr][i]!=prev)
            nodes[curr]+=countNodesAndPath(adjList[curr][i], curr);
    return nodes[curr];   
}
void build(int s, int e, int cth)
{
    if(s==e){
        segTree[cth].val=PathVal[s];
        return;
    }
    int mid=(s+e)/2;
    build(s, mid, cth*2);
    build(mid+1, e, cth*2+1);
    segTree[cth].val=segTree[cth*2].val+segTree[cth*2+1].val;
}
void refresh(int s, int e, int cth)
{
    int mid=(s+e)/2;
    int laz=segTree[cth].lazy;
    segTree[cth*2].val+=(mid-s+1)*laz;
    segTree[cth*2+1].val+=(e-mid)*laz;
    segTree[cth*2].lazy+=laz;
    segTree[cth*2+1].lazy+=laz;
    segTree[cth].lazy=0;
}
void update(int s, int e, int ters, int tere, int add, int cth)
{
    if(tere<s || e<ters)
        return;
    if(ters<=s && e<=tere)
    {
        segTree[cth].val+=(e-s+1)*add;
        segTree[cth].lazy+=add;
        return;
    }
    int mid=(s+e)/2;
    refresh(s, e, cth);
    update(s, mid, ters, tere, add, cth*2);
    update(mid+1, e, ters, tere, add, cth*2+1);
    segTree[cth].val=segTree[cth*2].val+segTree[cth*2+1].val;
}
int query(int s, int e, int n, int cth)
{
    if(n<s || e<n)
        return 0;
    if(n<=s && e<=n)
    {
        return segTree[cth].val;
    }
    int mid=(s+e)/2;
    refresh(s, e, cth);
    return query(s, mid, n, cth*2)+query(mid+1, e, n, cth*2+1);
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
        cin>>PathVal[firstEnc[i]];
    countNodesAndPath(1, 0);
    build(0, n-1, 1);
    int q;
    cin>>q;
    while(q--)
    {
        char type;
        int node;
        cin>>type>>node;
        if(type=='A')
        {
            int value;
            cin>>value;
            update(0,n-1,firstEnc[node],firstEnc[node]+nodes[node]-1,value,1);
        }
        else if(type=='Q')
        {
            cout<<query(0,n-1,firstEnc[node],1)<<endl;
        } 
    }
}