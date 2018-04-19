#include<iostream>
#define N 100
#define W 10000
#define INF 1000000007
using namespace std;
pair<int, int> items[N];//<weight, value>
int memo[N][W];
int main()
{
    int n, w;
    cin>>n>>w;
    for(int i=1; i<=n; i++)
        cin>>items[i].first>>items[i].second;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=w; j++)
            if(items[i].first<=j)
                memo[i][j]=max(memo[i-1][j], memo[i-1][j-items[i].first]+items[i].second);
            else
                memo[i][j]=memo[i-1][j];
    cout<<memo[n][w]<<endl;
}