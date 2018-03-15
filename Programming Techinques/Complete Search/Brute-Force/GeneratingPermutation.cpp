#include<iostream>
#include<vector>
#define N 10
using namespace std;
vector<int> permutation;
bool chosen[N];
void generate(int n){
    if(permutation.size()==n)
    {
        for(int i=0; i<n; i++)
            cout<<permutation[i]<<" ";
        cout<<endl;
        return;
    }
    for(int i=0; i<n; i++)
    {
        if(chosen[i])
            continue;
        chosen[i]=true;
        permutation.push_back(i);
        generate(n);
        chosen[i]=false;
        permutation.pop_back();
    }
}
int main()
{
    int n;
    cin>>n;
    generate(n);
}