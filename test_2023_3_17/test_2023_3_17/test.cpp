#include <iostream>
#include <stdio.h>
using namespace std;
struct S
{
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
};
int main()
{
	struct S s = { 0 };
	s.a = 10;
	s.b = 12;
	s.c = 3;
	s.d = 4;
	char* p = (char*)&s;
	cout << (int)*p << endl;
	cout << (int)*(p + 1) << endl;
	cout << (int)*(p + 2) << endl;
	return 0;
}
