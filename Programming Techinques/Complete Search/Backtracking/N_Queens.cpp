#include<iostream>
#define N 1000
using namespace std;

bool column[N], diag1[2*N], diag2[2*N];
long long count;
void search(int y, int n)
{
    if(y==n){
        count++;
        return;
    }
    for(int x=0; x<n; x++){
        if(column[x] || diag1[x+y] || diag2[x-y+n-1])
            continue;
        column[x] = diag1[x+y] = diag2[x-y+n-1] = true;
        search(y+1, n);
        column[x] = diag1[x+y] = diag2[x-y+n-1] = false;
    }
}

int main()
{
    int n;
    cin>>n;
    search(0, n);
    cout<<count<<endl;
}