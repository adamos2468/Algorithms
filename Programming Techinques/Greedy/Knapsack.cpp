#include<iostream>
#include<algorithm>
#define N 100000
using namespace std;
pair<double, pair<int, int> > items[N];//<density, <weight, value>>
int main()
{
    int n, w;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>items[i].second.first>>items[i].second.second;
        items[i].first=double(items[i].second.second)/items[i].second.first;
    }
    sort(items, items+n);
    double ans=0;
    for(int i=n-1; i>=0 && w>0; i--)
    {
        if(w>=items[i].second.first)
        {
            w-=items[i].second.first;
            ans+=items[i].second.second;
        }
        else
        {
            w=0;
            ans+=w*items[i].first;
        }
    }
    cout<<ans<<endl;
}