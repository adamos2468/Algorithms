#include<iostream>
#include<set>

using namespace std;
set<int> s;
//set<int> s={2,5,6,8};
multiset<int> ms;
int main()
{
	s.insert(3);
	s.insert(2);
	s.insert(5);
	cout<<s.count(3)<<endl;
	cout<<s.count(4)<<endl;
	s.erase(3);
	s.insert(4);
	cout<<s.count(3)<<endl;
	cout<<s.count(4)<<endl;

	cout<<s.size()<<endl;
	for(auto x:s)
		cout<<x<<endl;
	s.clear();
	/*-----------------------*/
	s.insert(5);
	s.insert(5);
	s.insert(5);
	cout<<s.count(5)<<endl;
	ms.insert(5);
	ms.insert(5);
	ms.insert(5);
	cout<<ms.count(5)<<endl;

	//Partial Deletion
	ms.erase(ms.find(5));
	cout<<ms.count(5)<<endl;
	
	//Complete Deletion
	ms.erase(5);
	cout<<ms.count(5)<<endl;

}
