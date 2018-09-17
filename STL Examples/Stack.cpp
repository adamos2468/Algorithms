#include<iostream>
#include<stack>
using namespace std;

int main()
{
	stack<int> s;
	s.push(3);
	s.push(2);
	s.push(5);
	cout << s.top()<<endl; // 5
	s.pop();
	cout << s.top()<<endl; // 2
}
