#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int a[]={12,14,6,3,8,13,4,-3};
vector<int> v={12,14,6,3,8,13,4,-3};
set<int> s={12,14,6,3,8,13,4,-3};
int n=8;
int main()
{
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	random_shuffle(v.begin(), v.end());

	sort(a, a+n);
	reverse(a, a+n);
	random_shuffle(a, a+n);

	set<int>::iterator boring_it=s.begin();
	auto it=s.begin();
	cout<<*it<<endl;

	for(auto it=s.begin(); it!=s.end(); it++)
		cout<<*it<<endl;

	it=s.end(); it--;
	cout<<*it<<endl;

	int x=69;
	it=s.find(x);
	if(it==s.end())
		cout<<"Not Found"<<endl;

	//Find Nearest
	x=7;
	it = s.lower_bound(x);
	if (it == s.begin()) {
		cout << *it << "\n";
	} else if (it == s.end()) {
		it--;
		cout << *it << "\n";
	} else {
		int a = *it; it--;
		int b = *it;
		if (x-b < a-x) cout << b << "\n";
		else cout << a << "\n";
	}
}
