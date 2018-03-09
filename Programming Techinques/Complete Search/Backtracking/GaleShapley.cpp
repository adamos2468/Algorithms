#include<iostream>
#include <queue>
#include <map>
#include <stdlib.h>
#define N 1001
using namespace std;

int manChoise[N][N], womanChoise[N][N];
int manIdx[N], womanIdx[N];
bool markedMen[N][N];
queue <int> freeMen;
map <int, int> solution;
map<int, int> sol;
void reset(int n)
{
    solution.clear();
    sol.clear();
    for(int i=1; i<=n; i++){
        freeMen.push(i);
        womanIdx[i]=n;
        manIdx[i]=1;
        for(int j=1; j<=n; j++)
            markedMen[i][j]=false;
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        int k;
        cin>>k;
        for(int j=1; j<=n; j++)
            cin>>womanChoise[k][j];
    }
    for(int i=1; i<=n; i++){
        int k;
        cin>>k;
        for(int j=1; j<=n; j++)
            cin>>manChoise[k][j];
    }
    reset(n);
    while(!freeMen.empty())
    {
        int m=freeMen.front();
        freeMen.pop();
        for(; manIdx[m]<=n; manIdx[m]++)
        {
            int w=manChoise[m][manIdx[m]];
            if(!markedMen[w][m])
            {
                if(solution[w]!=0)
                    freeMen.push(solution[w]);
                for(; womanChoise[w][womanIdx[w]]!=m; womanIdx[w]--)
                {
                    markedMen[w][womanChoise[w][womanIdx[w]]]=true;
                }
                solution[w]=m;
                sol[m]=w;
                break;   
            }
        } 
    }
    for(map<int, int>::iterator i=solution.begin(); i!=solution.end(); i++)
        cout<<"Man: "<<(i->second)<<" will marry "<<"Woman: "<<(i->first)<<endl;
}