#include<bits/stdc++.h>
#define MAXN 200001
using namespace std;
vector<int> adj[MAXN];
int height[MAXN];
int fromFather[MAXN];
int longest[MAXN];
pair< int, int > best[MAXN];
int getHeight(int node, int father){
    height[node]=0;
    priority_queue< pair<int, int> > localBest;
    for(auto x:adj[node])
        if(father!=x){
            height[node]=max(getHeight(x, node)+1, height[node]);
            localBest.push({-height[x], x});
            while(localBest.size()>2)
                localBest.pop();
        }
    if(localBest.size()==2){
        pair<int, int> temp;
        temp.second=localBest.top().second;
        localBest.pop();
        temp.first=localBest.top().second;
        localBest.pop();
        best[node]=temp;
    }else if(localBest.size()==1){
        pair<int, int> temp;
        temp.first=localBest.top().second;
        localBest.pop();
        temp.second=0;
        best[node]=temp;
    }else{
        best[node]={0, 0};
    }
    return height[node];
}

void getFather(int node, int father){
    if(father==0){
        fromFather[node]=0;
        longest[node]=height[node];
    }else{
        fromFather[node]=fromFather[father]+1;
        if(best[father].first==node){
            fromFather[node]=max(fromFather[node], height[best[father].second]+(best[father].second!=0)+1);
        }else{
            fromFather[node]=max(fromFather[node], height[best[father].first]+2);
        }
        longest[node]=max(fromFather[node], height[node]);
    }
    for(auto x:adj[node])
        if(x!=father)
            getFather(x, node);
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n-1; i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    getHeight(1, 0);
    getFather(1, 0);
    for(int i=1; i<=n; i++)
        cout<<longest[i]<<" ";
    cout<<endl;
}