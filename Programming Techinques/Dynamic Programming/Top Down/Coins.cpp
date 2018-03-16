#include<iostream>
#include<algorithm>
#define MAXCOINS 1000
#define MAXVAL 1000000
#define INF 1000000007
using namespace std;
int coins[MAXCOINS];
int memo[MAXVAL];
int subProb(int v, int c)
{
    if(v<0)
        return INF;
    else if(v==0)
        return 0;
    int ans=INF;
    for(int i=0; i<c; i++)
        ans=min(ans, subProb(v-coins[i], c));
    memo[v]=ans+1;
    return ans+1;
}
int main()
{
    int k, val, ans=0;
    cin>>k>>val;
    for(int i=0; i<k; i++)
        cin>>coins[i];
    cout<<subProb(val, k)<<endl;
}