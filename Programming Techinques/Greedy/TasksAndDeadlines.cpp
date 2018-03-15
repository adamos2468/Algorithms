#include<iostream>
#include<algorithm>
#define N 100000
using namespace std;

pair<int, int> tasks[N];//Second->Duration First->Deadline

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>tasks[i].first>>tasks[i].second;
    sort(tasks, tasks+n);
    int d=0, ans=0;
    for(int i=0; i<n; i++)
    {
        d+=tasks[i].first;
        ans+=tasks[i].second-d;
    }
    cout<<ans<<endl;    
}