#include<bits/stdc++.h>
#define MAXN 100000
using namespace std;

int main(){
    srand(time(NULL));
    int n=rand()%MAXN;
    string s="";
    for(int i=0; i<n; i++)
    {
        s+=(rand()%26)+'a';
    }
    cout<<s<<endl;
}