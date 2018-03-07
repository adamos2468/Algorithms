#include<iostream>
#include<vector>
#include<queue>
#include<list>
#define MAX_NODES 100000
#define MAX_EDGES 100000
using namespace std;
vector<queue<pair<int, int> > > adjQueue(MAX_NODES, queue< pair<int, int> >());
list<int>sol;
bool marked[MAX_EDGES];
list<int>::iterator Hierholzer(list<int>::iterator t)
{
    bool flag=false;
    list<int>::iterator ans=t;
    int curr=(*t);
    while(!adjQueue[curr].empty())
    {
        pair<int, int> epom=adjQueue[curr].front();
        adjQueue[curr].pop();
        if(marked[epom.second]==false)
        {
            marked[epom.second]=true;
            if(epom.first==(*t))
                break;
            if(flag==false){
                sol.insert(t, (*t));
                ans--;
                flag=true;
            }
            sol.insert(t, epom.first);
            curr=epom.first;
        }
    }
    return ans;
}
int main()
{
    int n, m, start;
    cin>>n>>m>>start;
    for(int i=0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        adjQueue[x].push(make_pair(y, i));
        adjQueue[y].push(make_pair(x, i));
    }
    list<int>::iterator i=sol.begin();
    sol.insert(i, start);
    i--;
    while(i!=sol.end())
    {
       // cout<<(*i)<<endl;
        if(adjQueue[(*i)].empty())
            i++;
        else
        {
            i=Hierholzer(i);
        }
        for(list<int>::iterator j=sol.begin(); j!=sol.end(); j++)
            cout<<(*j)<<" ";
        cout<<endl;
    }
    
}