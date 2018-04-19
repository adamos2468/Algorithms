#include<iostream>
#define N 1000
#define INF 1000000007
using namespace std;
int n, m;
int arr[N][N];
int memo[N][N];
void reset()
{
    for(int i=0; i<=m; i++)
        memo[0][i]=memo[n+1][i]=-INF;
    for(int i=0; i<=n; i++)
        memo[i][0]=memo[i][m+1]=-INF;
}
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>arr[i][j];
    reset();
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(i==1 && j==1)
                memo[i][j]=arr[i][j];
            else
                memo[i][j]=max(memo[i-1][j], memo[i][j-1])+arr[i][j];
        }
    }
    cout<<memo[n][m]<<endl;
}