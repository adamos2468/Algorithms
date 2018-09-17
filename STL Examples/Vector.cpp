#include<iostream>
#include<vector>

using namespace std;
vector<int> v;
/* vector<int> v={2,4,2,5,1};
 * vector<int> v(10);
 * vector<int> v(10, 5);
 */
int main()
{
	v.push_back(3);
	v.push_back(2);
	v.push_back(5);
	cout<<v[0]<<endl;
	cout<<v[1]<<endl;
	cout<<v[2]<<endl;
	for(int i=0; i<v.size(); i++)
		cout<<v[i]<<" ";
	cout<<endl;
	for(auto x:v)
		cout<<x<<" ";
	cout<<endl;
	
	v.clear();
	v.push_back(5);
	v.push_back(2);
	cout<<v.back()<<endl;
	v.pop_back();
	cout<<v.back()<<endl;	
}
