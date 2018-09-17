#include<iostream>
#include<map>

using namespace std;
map<string, int>m;
int main()
{
	m["monkey"]=4;
	m["banana"]=3;
	m["aggouri"]=9;
	cout<<m["aggouri"]<<endl;

	cout<<m["pizza"]<<endl;

	if(m.count("monkey")){
		//Key Exists
	}

	for(auto x:m)
		cout<<x.first<<" "<<x.second<<endl;
}
