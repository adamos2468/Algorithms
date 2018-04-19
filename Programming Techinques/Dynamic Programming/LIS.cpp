#include<iostream>
#define N 1000
using namespace std;
int arr[N];
int memo[N];
int LIS(int h)
{
    if(h==0)
        return 1;
    if(memo[h]!=0)
        return memo[h];
    int ans=1;
    for(int i=0; i<h; i++)
        if(arr[i]<arr[h])
            ans=max(ans, LIS(i));
    memo[h]=++ans;
    return ans;
}
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<LIS(n-1)<<endl;
}