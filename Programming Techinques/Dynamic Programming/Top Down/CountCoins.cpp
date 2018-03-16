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
        return 0;
    else if(v==0)
        return 1;
    int ans=0;
    for(int i=0; i<c; i++)
        ans+=subProb(v-coins[i], c);
    memo[v]=ans;
    return ans;
}
int main()
{
    int k, val, ans=0;
    cin>>k>>val;
    for(int i=0; i<k; i++)
        cin>>coins[i];
    cout<<subProb(val, k)<<endl;
}