//#include <iostream>
//using namespace std;
//class A {
//public:
//	A(int age, int* p)
//		:_age(age)
//		, _p(p)
//	{}
//	int _age;
//	int* _p;
//};
//int main() {
//	int* x = new int(12);
//	A* a = new A(10, x);
//	cout << "¶ÑÇø£º" << a << endl;
//	cout << &(a->_age) << endl;
//	cout << "¶ÑÇø£º" << a->_p << endl;
//	int b = 10;
//	cout <<"Õ»Çø£º"<< &b << endl;
//	return 0;
//}


#include <iostream>
using namespace std;
class A {
public:
	virtual ~A() {
	}
	int _a = 1;
};
class B : public A {
public:
	~B() {
		cout << "~B()" << endl;
		if (_ptr)
			delete _ptr;
	}
	int _b = 3;
	int* _ptr = nullptr;
};
int main() {
	A* p = new B;
	//...
	//cout << *((int*)p--) << endl;
	//A* a = new A;
	//B* b = new B;
	//cout << sizeof(int) << endl;
	//cout << sizeof(A) << endl;
	//cout << *(int*)a << endl;
	//cout << *((int*)a+1) << endl;
	//cout << sizeof(B) << endl;
	delete p;
	B* px = new B;
	px->_b = 5;
	delete px;
	return 0;
}
