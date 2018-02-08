#include<iostream>
#include<vector>
#include<stack>
#include<set>
#define MAX_NODES 200002
#define MAX_LITERALS 100001
using namespace std;

vector< vector<int> > strList(MAX_NODES, vector<int>());
vector< vector<int> > revList(MAX_NODES, vector<int>());
vector< vector<int> > compList(MAX_NODES, vector<int>());
vector<int>row;
vector< vector<int> > compGroups;
bool strVis[MAX_NODES], revVis[MAX_NODES], compVis[MAX_NODES];
int comp[MAX_NODES];
stack<int> order;
int literal[MAX_LITERALS];//2->FALSE 1->TRUE 0->UNKNOWN
int enCo(int a)
{
    if(a<0)
        return -(a<<1);
    else
        return (a<<1)-1;
}
int deCo(int a)
{
    if(a%2)
        return (a+1)>>1;
    else
        return a>>1;
}
void addEdges(int a, int b)
{
    strList[enCo(-a)].push_back(enCo(b));
    strList[enCo(-b)].push_back(enCo(a));
    revList[enCo(b)].push_back(enCo(-a));
    revList[enCo(a)].push_back(enCo(-b));
}
void dfs1(int s)
{
    strVis[s]=true;
    for(int i=0; i<strList[s].size(); i++)
        if(!strVis[strList[s][i]])
            dfs1(strList[s][i]);
    order.push(s);
}
void dfs2(int s, int wh)
{
    row.push_back(s);
    comp[s]=wh;
    revVis[s]=true;
    for(int i=0; i<revList[s].size(); i++)
        if(!revVis[revList[s][i]])
            dfs2(revList[s][i], wh);
}
void assignLit(int l)
{
    int d=deCo(l);
    //cout<<d<<" Assigned\n";

    if(l%2==0)
        literal[d]=2;//FALSE
    else
        literal[d]=1;//TRUE
}
bool assignComp(int c)
{
    //cout<<c<<": ";
    set<int> saw;
    for(int i=0; i<compGroups[c].size(); i++){
        int v=deCo(compGroups[c][i]);
        if(saw.find(v)==saw.end()){
            //cout<<compGroups[c][i]<<" ";
            saw.insert(v);
            if(literal[v]==0)
                assignLit(compGroups[c][i]);
        }
        else
            return false;
    }
    //cout<<endl;
    return true;
}
bool topSort(int s)
{
    bool sol=true;
    compVis[s]=true;
    for(int i=0; i<compList[s].size(); i++)
        if(!compVis[compList[s][i]])
            sol&=topSort(compList[s][i]);
    return assignComp(s);
}
int main()
{
    int n, k;
    cin>>n>>k;
    while(k--)
    {
        int x, y;
        cin>>x>>y;
        addEdges(x, y);
    }
    for(int i=1; i<=2*n; i++)
        if(!strVis[i])
            dfs1(i);
    int counter=1;
    compGroups.push_back(vector<int>());
    while(!order.empty()){
        int node=order.top();
        order.pop();
        if(!revVis[node]){
            row.clear();
            dfs2(node, counter);
            compGroups.push_back(row);
            counter++;
        }
    }
    for(int s=1; s<=2*n; s++)
    {
        for(int i=0; i<strList[s].size(); i++)
        {
            if(comp[s]!=comp[strList[s][i]])
                compList[comp[s]].push_back(comp[strList[s][i]]);
        }
    }
    for(int i=1; i<counter; i++)
    {
        if(!compVis[i])
            if(!topSort(i))
            {
                cout<<"There is no solution!!!\n";
                return 0;
            }
    }
    for(int i=1; i<=n; i++)
        if(!(literal[i]==0))
            cout<<"x"<<i<<": "<<(literal[i]==1?"True":"False")<<endl;
}