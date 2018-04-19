#include<iostream>
#include<string>
#define MAX_N 1000
using namespace std;
string s1, s2;
int dp[MAX_N][MAX_N];
int main()
{
    cin>>s1>>s2;
    for(int i=1; i<s1.size()-1; i++)
        for(int j=1; j<s2.size()-1; j++)
            if(s1[i]==s2[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    cout<<dp[s1.size()-1][s2.size()-1]<<endl;
}