#include<iostream>
#include<algorithm>
#define MAXCOINS 1000
#define MAXVAL 1000000
#define INF 1000000007
using namespace std;
int coins[MAXCOINS];
int memo[MAXVAL];
int main()
{
    int k, val, ans=0;
    cin>>k>>val;
    for(int i=0; i<k; i++)
        cin>>coins[i];
    for(int i=0; i<=val; i++)
    {
        if(i==0)
            memo[i]=1;
        else{
            memo[i]=0;
            for(int j=0; j<k; j++)
                if(i-coins[j]>=0)
                    memo[i]+=memo[i-coins[j]];
        }
    }
    cout<<memo[val]<<endl;
}