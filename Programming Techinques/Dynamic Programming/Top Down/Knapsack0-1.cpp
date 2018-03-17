#include<iostream>
#define N 100
#define W 10000
#define INF 1000000007
using namespace std;
pair<int, int> items[N];//<weight, value>
int memo[N][W];
int knapsack(int it, int wei)
{
    if(wei==0 || it<0)
        return 0;
    if(memo[it][wei]!=0)
        return memo[it][wei];
    if(wei>=items[it].first)
        memo[it][wei]=max(knapsack(it-1, wei), knapsack(it-1, wei-items[it].first)+items[it].second);
    else
        memo[it][wei]=knapsack(it-1, wei);
    return memo[it][wei];
}
int main()
{
    int n, w;
    cin>>n>>w;
    for(int i=0; i<n; i++)
        cin>>items[i].first>>items[i].second;
    cout<<knapsack(n-1, w)<<endl;
}