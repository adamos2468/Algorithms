#include<iostream>
#include<vector>
#include<complex>
#include<math.h>
using namespace std;
vector< complex<double> > a;
vector< complex<double> > b;
vector< double > c;
vector< complex<double> > d;
bool isZero(double num)
{
    return (abs(num)<(10e-9));
}
complex<double> rootOfUnity(int j, int k)
{
    double theta=(2*M_PI)/k;
    double real=cos(j*theta);
    double imag=sin(j*theta);
    if(isZero(real))
        real=0;
    if(isZero(imag))
        imag=0;
    complex<double> ans=complex<double>(real, imag);
    return ans;
}
vector< complex<double> >FFT(vector< complex<double> > x)
{
    int n=x.size();
    vector< complex<double> > ans;
    if(n==1)
    {
        ans.push_back(x[0]);
        ans.push_back(x[0]);
        return ans;
    } 
    vector< complex<double> > even, odd;
    for(int i=0; i<n; i++)
        if(i%2==0)
            even.push_back(x[i]);
        else
            odd.push_back(x[i]);
    even=FFT(even);
    odd=FFT(odd);
    for(int i=0; i<n*2; i++)
    {
        complex<double> w=rootOfUnity(i, 2*n);
        ans.push_back(even[i%n]+w*odd[i%n]);
    }  
    return ans;
}
vector< complex<double> > mul(vector< complex<double> > a, vector< complex<double> > b)
{
    vector< complex<double> > ans;
    for(int i=0; i<a.size(); i++)
        ans.push_back(a[i]*b[i]);
    return ans;
}
vector< complex<double> > invFFT(vector< complex<double> > x)
{
    int n=x.size();
    vector< complex<double> > ans;
    if(n==1)
    {
        ans.push_back(x[0]);
        return ans;
    }
    vector< complex<double> > even, odd;
    for(int i=0; i<n; i++)
        if(i%2==0)
            even.push_back(x[i]);
        else
            odd.push_back(x[i]);
    even=invFFT(even);
    odd=invFFT(odd);
    for(int i=0; i<n; i++)
    {
        complex<double> w=rootOfUnity(i, n);
        ans.push_back(even[i%(n/2)]+w*odd[i%(n/2)]);
    }
    return ans;  
}
vector<double>getFromINV(vector< complex<double> > d)
{
    int n=d.size();
    vector<double> ans;
    double c_i=d[0].real()/(n);
    ans.push_back(c_i);
    for(int i=d.size()-1; i>=2; i--)
    {
        c_i=d[i].real()/(n);
        ans.push_back(c_i);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        double x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=0; i<n; i++)
    {
        double x;
        cin>>x;
        b.push_back(x);
    }
    a=FFT(a);
    b=FFT(b);
    d=mul(a, b);
    d=invFFT(d);
    c=getFromINV(d);
    for(int i=0; i<c.size(); i++)
        cout<<c[i]<<" ";
    cout<<endl; 
}