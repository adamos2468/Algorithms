#include<iostream>
#define N 64
using namespace std;

int Sudoku[N][N];
unsigned long long rows[N], col[N];

bool solve(int r, int c, int n)
{
    if(Sudoku[r][c]==-1)
    {
        for(int i=0; i<n; i++)
        {
            if((rows[r]&(1<<i))==0 && (col[c]&(1<<i))==0)
            {
                rows[r]|=1<<i; col[c]|=1<<i; Sudoku[r][c]=i;
                bool ans;
                if(c==n-1 && r==n-1)
                    return true;
                else if(r==n-1)
                    ans=solve(0, c+1, n);
                else
                    ans=solve(r+1, c, n);
                if(ans==true)
                    return true;
                rows[r]&=~(1<<i); col[c]&=~(1<<i); Sudoku[r][c]=-1;
            }
        }
        return false;
    }
    bool ans;
    if(c==n-1 && r==n-1)
        return true;
    else if(r==n-1)
        ans=solve(0, c+1, n);
    else
        ans=solve(r+1, c, n);
    return ans;   
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>Sudoku[i][j];
            Sudoku[i][j]--;
            rows[i]|=(1<<Sudoku[i][j]);
            col[j]|=(1<<Sudoku[i][j]);
        }
    }
    bool acc=solve(0, 0, n);
    if(acc)
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cout<<(++Sudoku[i][j])<<" ";
            cout<<endl;
        }
    else
        cout<<"No Solution\n";
}