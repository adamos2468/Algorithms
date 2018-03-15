#include<iostream>
#include<algorithm>
#define MAXCOINS 1000
using namespace std;

int coins[MAXCOINS];

int main()
{
    int k, val, ans=0;
    cin>>k>>val;
    for(int i=0; i<k; i++)
        cin>>coins[i];
    sort(coins, coins+k);
    for(int i=k-1; i>=0; i--){
        ans+=val/coins[i];
        val%=coins[i];
    }
    cout<<ans<<endl;
}