#include<iostream>
#define N 1000
using namespace std;
int arr[N];
int memo[N];
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    memo[0]=1;
    for(int i=1; i<n; i++){
        memo[i]=1;
        for(int j=0; j<i; j++)
            if(arr[i]>arr[j])
                memo[i]=max(memo[i], memo[j]+1);
    }
    cout<<memo[n-1]<<endl;
}