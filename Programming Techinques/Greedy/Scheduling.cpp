#include<iostream>
#include<algorithm>
#define N 100000
using namespace std;

pair<int, int> tasks[N];//First->End Second->Start

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>tasks[i].second>>tasks[i].first;
    sort(tasks, tasks+n);
    int d=0, ans=0;
    for(int i=0; i<n; i++)
    {
        if(tasks[i].second>=d)
        {
            d=tasks[i].first;
            ans++;
        }
    }
    cout<<ans<<endl;    
}