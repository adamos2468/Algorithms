#include<bits/stdc++.h>
#define MAXN 100000
using namespace std;

struct node{
    int mini, maxi, sum;
    int lazy;
};

node seg[4*MAXN+10];
int a[MAXN];

/*
Calculates the parent's value from two children
*/

node merge(node a, node b){
    a.mini=min(a.mini, b.mini);
    a.maxi=max(a.maxi, b.maxi);
    a.sum+=b.sum;
    a.lazy=0;
    return a;
}

node refresh(int s, int e, int cth){

     int mid=(s+e)/2;
    int leftSize=mid-s+1; //Range size=e-s+1 (formula)
    int rightSize=e-mid; //e-(mid+1)+1
    
    seg[cth*2].lazy+=seg[cth].lazy;
    if(seg[cth].lazy)

    seg[cth*2+1].lazy+=seg[cth].lazy;
    if(seg[cth].lazy)
    
    seg[cth*2].maxi+=seg[cth].lazy;
    seg[cth*2+1].maxi+=seg[cth].lazy;
    
    seg[cth*2].mini+=seg[cth].lazy;
    seg[cth*2+1].mini+=seg[cth].lazy;

   
    seg[cth*2].sum+=seg[cth].lazy*leftSize;
    seg[cth*2+1].sum+=seg[cth].lazy*rightSize;
    
    seg[cth].lazy=0;
}

/*
Initializes the Segment Tree based on array a
*/
void build(int s, int e, int cth){
    if(s==e){
        seg[cth].mini=seg[cth].maxi=seg[cth].sum=a[s];
        seg[cth].lazy=0;
        return;
    }

    int mid=(s+e)/2;
    build(s, mid, cth*2);
    build(mid+1, e, cth*2+1);
    seg[cth].lazy=0;
    seg[cth]=merge(seg[cth*2],seg[cth*2+1]);
}
/*
Get the answers to the querries for the range[ters, tere]
*/
node querry(int s, int e, const int ters, const int tere, int cth){
    if(ters<=s && e<=tere)
        return seg[cth];
    
    if(e<ters || tere<s){
        node bad; 
        bad.mini=1000000007; bad.maxi=-1000000007; bad.sum=0;    
        return bad;
    }
    
    refresh(s,e,cth);

    int mid=(s+e)/2;
    node leftChild=querry(s,mid, ters, tere, cth*2);
    node rightChild=querry(mid+1, e, ters, tere, cth*2+1);
    
    return merge(leftChild, rightChild);
}

/*
Add u to to every number in the range [ters, tere]
*/
void update(int s, int e, const int u,const int ters, const int tere, int cth){
    if(ters<=s && e<=tere){
        seg[cth].mini+=u;
        seg[cth].maxi+=u;
        int meg=e-s+1;
        seg[cth].sum+=meg*u;
        seg[cth].lazy+=u;
        return;
    }
    if(e<ters || tere<s)
        return;
    
    refresh(s,e,cth);

    int mid=(s+e)/2;
    update(s,mid,u, ters, tere, cth*2);
    update(mid+1, e, u,ters, tere, cth*2+1);
    seg[cth]=merge(seg[cth*2],seg[cth*2+1]);
}

int main(){
    int n, q;
    cin>>n>>q;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    build(0, n-1, 1);
    while(q--){
        char t;
        cin>>t;
        if(t=='U'){
            int s, e, u;
            cin>>s>>e>>u;
            update(0, n-1, u, s, e,1);
        }else{
            int s, e;
            cin>>s>>e;
            node ans=querry(0, n-1, s, e, 1);
            cout<<"Maximum Value: "<<ans.maxi<<endl;
            cout<<"Minimum Value: "<<ans.mini<<endl;
            cout<<"Sum: "<<ans.sum<<endl<<endl;
        }
    }
}