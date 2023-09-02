//#include <iostream>
//using namespace std;
//int g1;
//int g2 = 10;
//int main() {
//	int a = 10;
//	int b = 20;
//	int* p1 = new int(10);
//	int* p2 = new int(20);
//	cout << "a: " << &a << endl;
//	cout << "b: " << &b << endl;
//	cout << "p2: " << p2 << endl;
//	cout << "p1: " << p1 << endl;
//	cout << "g1: " << &g1 << endl;
//	cout << "g2: " << &g2 << endl;
//	return 0;
//
//}

//#include <iostream>
//using namespace std;
//class A {
//public:
//	A() {
//		cout << "A()" << endl;
//	}
//	~A() {
//		cout << "~A()" << endl;
//	}
//};
//int main() {
//	A* ptr = new A;
//	ptr->~A();
//	new(ptr)A; //定位new
//	delete ptr;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//template<class T, int N>
//class A {
//public:
//	A(const T& val)
//		:_val(val)
//	{
//		cout << "N: " << N << endl;
//		cout << "val: " << _val << endl;
//	}
//private:
//	T _val;
//};
//int main() {
//	A<int, 19> a(20);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//template<class T1, class T2>
//void func(const T1& a, const T2& b) {
//	cout << typeid(T1).name() << endl;
//	cout << typeid(T2).name() << endl;
//}
//template<>
//void func<int, float>(const int& a, const float& b) {
//	cout << "特化版本" << endl;
//}
//int main() {
//	func(10, 20.1);
//	func<int, int>(10, 20.1);
//	func<int, float>(10, 10.1);
//	return 0;
//}

#include <iostream>
using namespace std;
template<class T1, class T2>
class A {
public:
	A() {
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
private:
	T1 _a;
	T2 _b;
};
template<>
class A<int, float> {
public:
	A() {
		cout << "特化版本" << endl;
	}
private:
	int _a;
	float _b;
};
template<class T1, class T2>
class A<T1&, T2*> {
public:
	A() {
		cout << "进一步限制版本" << endl;
	}
private:
	T1 _a;
	T2 _b;
};
int main() {
	A<int, double> a;
	A<int, float> b;
	A<int&, int*> c;
	return 0;
}