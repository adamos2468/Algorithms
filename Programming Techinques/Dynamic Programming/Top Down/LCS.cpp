#include<iostream>
#include<string>
#define MAX_N 1000
using namespace std;
string s1, s2;
bool check[MAX_N][MAX_N];
int memo[MAX_N][MAX_N];
int LCS(int i, int j)
{
    if(i==0 || j==0)
        return 0;
    if(check[i][j])
        return memo[i][j];
    check[i][j]=true;
    if(s1[i]==s2[j])
        memo[i][j]=LCS(i-1, j-1)+1;
    else
        memo[i][j]=max(LCS(i-1, j), LCS(i, j-1));
    return memo[i][j];
}
int main()
{
    cin>>s1>>s2;
    int i=s1.size(), j=s2.size();
    s1=""+s1;
    s2=""+s2;
    cout<<LCS(i, j)<<endl;
}