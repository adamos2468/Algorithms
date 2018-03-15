#include<iostream>
#include<vector>
using namespace std;
vector<int> subSet;
void generate(int k, int n){
    if(k==n)
    {
        for(int i=0; i<subSet.size(); i++)
            cout<<subSet[i]<<" ";
        cout<<endl;
        return;    
    }
    generate(k+1, n);
    subSet.push_back(k);
    generate(k+1, n);
    subSet.pop_back();
}
int main()
{
    int n;
    cin>>n;
    generate(0, n);
}