#include<iostream>
#include<vector>
#include<map>
using namespace std;
map<long long, long long>sets[2];
vector<long long> vals[2];
void generate(vector<long long> val, int team){
    int n=val.size();
    for(int i=0; i<(1<<n); i++)
    {
        long long sum=0;
        for(int j=0; j<n; j++)
            if(i&(1<<j))
                sum+=val[j];
        sets[team][sum]=i;
    }
}
int main()
{
    int n, x;
    cin>>n>>x;
    for(int i=0; i<n; i++)
    {
        int a, t=i/(n/2);
        cin>>a;
        vals[t].push_back(a);
    }
    generate(vals[0], 0);
    generate(vals[1], 1);
    map<long long, long long>::iterator h;
    for(h=sets[0].begin(); h!=sets[0].end(); h++){
        long long temp=h->first;
        map<long long, long long>::iterator u=sets[1].find(x-temp);
        if(u!=sets[1].end())
        {
            for(int i=0; i<vals[0].size(); i++)
                if((h->second)&(1<<i))
                    cout<<vals[0][i]<<" ";
            for(int i=0; i<vals[1].size(); i++)
                if((u->second)&(1<<i))
                    cout<<vals[1][i]<<" ";
            cout<<endl;
            return 0;
        }
    }
    cout<<"No Sum"<<endl;
}