#include<string>
#include<iostream>
using namespace std;

int main(){
	string a="souvla";
	string b=a+a;
	cout<<b<<endl;
	b[5]='v';
	cout<<b<<endl;
	string c=b.substr(3,4);
	cout<<c<<endl;
}
