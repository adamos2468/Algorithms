#include<iostream>
#include<vector>
using namespace std;


void generate(int n){
    for(int i=0; i<(1<<n); i++)
    {
        vector<int> subSet;
        for(int j=0; j<n; j++)
        {
            if(i&(1<<j))
            {
                subSet.push_back(j);
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    generate(n);
}