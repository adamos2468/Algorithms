#include<iostream>
#define N 1002
using namespace std;

bool pin[N][N];
long long count=0, cells=0;
void reset(int n, int m)
{
    for(int i=0; i<=m; i++)
        pin[0][i]=pin[n+1][i]=true;
    for(int i=0; i<=n; i++)
        pin[i][0]=pin[i][m+1]=true;
}
bool isOK(int n, int m, int i, int j)
{
    if(i==n && j==m)
        return false;
    if(pin[i+1][j] && pin[i-1][j] && !pin[i][j-1] && !pin[i][j+1])
        return false;
    return true;
}
void search(int n, int m, int i, int j)
{
    pin[i][j]=true; cells++;
    if(i==n && j==m && cells==n*m)
        count++;
    else if(isOK(n, m, i, j))
    {
        if(!pin[i+1][j] && !(i==1 && j==1))
            search(n, m, i+1, j);
        if(!pin[i-1][j])
            search(n, m, i-1, j);
        if(!pin[i][j-1])
            search(n, m, i, j-1);
        if(!pin[i][j+1])
            search(n, m, i, j+1);
    }
    pin[i][j]=false; cells--;
}
int main()
{
    int n, m;
    cin>>n>>m;
    reset(n, m);
    search(n, m, 1, 1);
    count<<=1;
    cout<<count<<endl;
}