#include<iostream>
#include<bitset>

using namespace std;
bitset<10>s;

int main()
{
	s[1]=1;
	s[3] = 1;
	s[4] = 1;
	s[7] = 1;
	cout << s[4] << "\n";
	cout << s[5] << "\n";

	bitset<10> s1(string("0010011010")); 
	cout << s1[4] << "\n";
	cout << s1[5] << "\n";
	cout << s1.count() << "\n";

	bitset<10> a(string("0010110110"));
	bitset<10> b(string("1011011000"));
	cout << (a&b) << "\n"; 
	cout << (a|b) << "\n"; 
	cout << (a^b) << "\n"; 
}
