//#include <iostream>
//using namespace std;
//void func(int a, int b, int c = 2, int d = 4) {
//	cout << a << " " << b << " " << c << " " << d << endl;
//}
//int main() {
//	func(1, 2);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//extern "C" {
//	void func(int a, double b) {
//		cout << "func1" << endl;
//	}
//	int func(double a, int b) {
//		cout << "func2" << endl;
//		return 1;
//	}
//}
//int main() {
//	func(1, 2.2);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//inline int add(int a, int b) {
//	return a + b;
//}
//int main() {
//	int ret = add(3, 4);
//	int a = 10;
//	auto& e = a;
//	cout << typeid(e).name() << endl;
//	return 0;
//}

//#include <iostream>
//inline int Add(int a, int b)
//{
//	return a + b;
//}
//int main()
//{
//	int ret = Add(1, 2);
//
//	return 0;
//}

#include <iostream>
using namespace std;
class A {
public:
	A() {
		cout << "A()" << endl;
	}
	~A() {
		cout << "~A()" << endl;
	}
};
class B {
public:
	B() {
		cout << "B()" << endl;
	}
	~B() {
		cout << "~B()" << endl;
	}
};
int main() {
	cout << sizeof(A) << endl;
	A a;
	B b;
	return 0;
}