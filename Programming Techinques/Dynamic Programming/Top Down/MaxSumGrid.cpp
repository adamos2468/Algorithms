#include<iostream>
#define N 1000
#define INF 1000000007
using namespace std;
int n, m;
int arr[N][N];
int memo[N][N];
int sum(int i, int j)
{
   if(i==0 || j==0)
        return -INF;
    if(i==1 && j==1)
        return arr[i][j];
    if(memo[i][j]!=0)
        return memo[i][j];
    memo[i][j]=max(sum(i-1, j), sum(i, j-1))+arr[i][j];
    return memo[i][j];
}
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>arr[i][j];
    cout<<sum(n, m)<<endl;
}