#include<bits/stdc++.h>
#define MAXN 15
#define INF 100

using namespace std;

int main(){
    srand(time(NULL));
    int n=rand()%MAXN;
    n++;
    int q=rand()%MAXN;
    q++;
    cout<<n<<" "<<q<<endl;
    for(int i=0; i<n; i++)
        cout<<(rand()%INF)<<" ";
    cout<<endl;
    for(int i=0; i<q; i++){
        int t=rand()%2;
        int x=rand()%n, y=rand()%n;
        if(y<x)
            swap(x, y);
        if(t)
            cout<<"U "<<x<<" "<<y<<" "<<rand()%INF<<endl;
        else
            cout<<"Q "<<x<<" "<<y<<endl;
    }
}