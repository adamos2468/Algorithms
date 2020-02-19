#include<bits/stdc++.h>
#define MAXN 200010
#define K 20
using namespace std;
int arr[MAXN];
int st[MAXN][K];
void createSparce(int n){
    for (int i = 0; i < n; i++)
    st[i][0] = arr[i];

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}
int rmq(int l, int r){
    int dist=(r-l)+1;
    int msb=(int)log2(dist);
    return min(st[l][msb], st[r - (1 << msb) + 1][msb]);;
}
int main(){
    int n, q;
    cin>>n>>q;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    createSparce(n);
    while(q--){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        cout<<rmq(a,b)<<endl;
    }
}