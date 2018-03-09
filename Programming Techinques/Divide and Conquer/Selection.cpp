#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int selection(vector<int> a, int k)
{
    /*if(a.size()<5)
    {
        sort(a.begin(), a.end());
        return a[k];
    }*/
    if(a.size()<=(1<<15))
    {
        sort(a.begin(), a.end());
        return a[k];
    }
    vector<int> median;
    for(vector<int>:: iterator i=a.begin(); (i+5)<=a.end(); i+=5)
    {
        sort(i, i+5);
        median.push_back(*(i+2));
    }
    int val=selection(median, median.size()/2);
    vector<int> l, r;
    for(vector<int>:: iterator i=a.begin(); i!=a.end(); i++)
    {   
        if((*i)<=val)
            l.push_back(*i);
        else
            r.push_back(*i);
    }
    if(l.size()>k)
        return selection(l, k);
    else
        return selection(r, k-l.size());
}
int main()
{
    int n, k;
    vector<int> pin;
    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        pin.push_back(x);
    }
    cout<<selection(pin, k)<<endl;
}