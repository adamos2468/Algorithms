#include<bits/stdc++.h>
#define MAXN 200001
using namespace std;
int n, q;
long long b[MAXN];
int arr[MAXN];
void add(int x, int a){
    while(x<=n){
        b[x]+=a;
        x+=(x&-x);
    }
}
long long sum(int x){
    long long ans=0;
    while(x>0){
        ans+=b[x];
        x-=(x&-x);
    }
    return ans;
}
long long range(int a, int b){
    return sum(b)-sum(a-1);
}
int main(){
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        add(i, arr[i]);
    }
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            long long x, u;
            cin>>x>>u;
            add(x, u-arr[x]);
            arr[x]=u;
        }else{
            int x, y;
            cin>>x>>y;
            cout<<range(x, y)<<endl;
        }
    }
}