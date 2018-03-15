#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> permutation;
void generate(int n){
    for(int i=0; i<n; i++)
        permutation.push_back(i);
    do{
        for(int i=0; i<n; i++)
            cout<<permutation[i]<<" ";
        cout<<endl;
    }while(next_permutation(permutation.begin(), permutation.end()));
}
int main()
{
    int n;
    cin>>n;
    generate(n);
}