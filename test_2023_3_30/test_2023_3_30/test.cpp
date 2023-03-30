//#include <iostream>
//using namespace std;
//class A {
//public:
//	A() {
//		cout << "A()" << endl;
//	}
//	A(const A& a) {
//		cout << "A(const A&)" << endl;
//	}
//};
//int main() {
//	A a;
//	A tmp(a);
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class A {
//public:
//	A()
//		:b(a+10)
//		,a(10)
//	{
//		cout << "a:" << a << endl;
//		cout << "b:" << b << endl;
//	}
//private:
//	int a;
//	int b;
//};
//int main() {
//	A a;
//	return 0;
//}


//#include <iostream>
//#include <cstdio>
//using namespace std;
//class A {
//public:
//	A() {
//		cout << "A()" << endl;
//	}
//	void Print() {
//		cout << _a << endl;
//	}
//	void Print2() {
//		cout << _a << endl;
//	}
//	static int GetA() {
//		return _a;
//	}
//	static int _a;
//};
//int A::_a = 10;
//int main() {
//	A a;
//	//cout << A::_a << endl;
//	//cout << a._a << endl;
//	//cout << A()._a << endl;
//	cout << a.GetA() << endl;
//	A b;
//	cout << b.GetA() << endl;
//	cout << A::GetA() << endl;
//	cout << A::GetA << endl;
//	cout << &A::GetA << endl;
//	cout << a.GetA << endl;
//	cout << &A::Print << endl;
//	cout << &A::Print2 << endl;
//	printf("%p\n", &A::Print);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main() {
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	cout << "a: " << &a << endl;
//	cout << "b: " << &b << endl;
//	cout << "c: " << &c << endl;
//	cout << *(&b + 3) << endl;
//
//	int* p1 = new int;
//	int* p2 = new int;
//	int* p3 = new int;
//	cout << "p1: " << p1 << endl;
//	cout << "p2: " << p2 << endl;
//	cout << "p3: " << p3 << endl;
//	delete p1;
//	int* p4 = new int;
//	cout << "p4: " << p4 << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main() {
//	string* p1 = new string("a");
//	cout << *p1 << endl;
//	string* p2 = new string[5]{ "a","b","c","d","e" };
//	for (int i = 0; i < 5; i++) {
//		cout << *(p2 + i) << endl;
//	}
//	delete p1;
//	delete[] p2;
//	return 0;
//}


//#include <iostream>
//#include <cstdio>
//using namespace std;
//class A {
//public:
//	A(int a = 10)
//		:_a(a)
//	{
//		cout << "A()" << endl;
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//int main() {
//	A* p = (A*)malloc(sizeof(A));
//	//new(p)A;
//	new(p)A(20);
//	return 0;
//}


//#include <iostream>
//using namespace std;
//template<class T>
//void Print(const T& a, const T& b) {
//	cout << typeid(a).name() << endl;
//}
//void Print(const double& a, const double& b) {
//	cout << a << " " << b << endl;
//}
//template<class T, size_t N>
//class A {
//public:
//	A() {
//		cout << N << endl;
//	}
//};
//int main() {
//	Print(1.1, 2.2);
//	Print<double>(1, 2.2);
//	A<int, 23> a;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//template<class T>
//void Print(const T& a, const T& b) {
//	cout << typeid(a).name() << endl;
//}
//template<>
//void Print<int>(const int& a, const int& b) {
//	cout << "int 特化" << endl;
//}
//template<class T1, class T2>
//class A {
//public:
//	A() {
//		cout << "A()" << endl;
//	}
//private:
//	T1 _a;
//	T2 _b;
//};
//template<>
//class A<int, int> {
//public:
//	A() {
//		cout << "int 特化" << endl;
//	}
//private:
//	int _a;
//	int _b;
//};
//template<class T2>
//class A<double, T2> {
//public:
//	A() {
//		cout << "部分特化" << endl;
//	}
//private:
//	double _a;
//	T2 _b;
//};
//template<class T1, class T2>
//class A<T1*, T2*> {
//public:
//	A() {
//		cout << "进一步限制" << endl;
//		cout << typeid(_a).name() << endl;
//	}
//private:
//	T1* _a;
//	T2* _b;
//};
//int main() {
//	Print(1.1, 2.2);
//	Print(2, 4);
//	A<int, double> a1;
//	A<int, int> a2;
//	A<double, int> a3;
//	A<int*, double*> a4;
//	clog << "this is a test" << endl;
//	return 0;
//}


//#include <iostream>
//#include <string>
//#include <sstream>
//using namespace std;
//int main() {
//	stringstream f;
//	double a = 10.231;
//	f << a;
//	string s;
//	f >> s;
//	cout << s << endl;
//	
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class A {
//public:
//	A() {
//		cout << "A()" << endl;
//	}
//	void Print() {
//		cout << "aaa" << endl;
//	}
//};
//class B : protected A {
//public:
//	B() {
//		cout << "B()" << endl;
//	}
//};
//int main() {
//	A a;
//	B b;
//	a.Print();
//	//b.Print();
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class A {
//public:
//	A() {
//		cout << "A()" << endl;
//	}
//	virtual void Print() {
//		cout << "aaa" << endl;
//	}
//};
//class B : public A {
//public:
//	B() {
//		cout << "B()" << endl;
//	}
//};
//int main() {
//	A a;
//	B b;
//	a.Print();
//	b.Print();
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//class A {
//public:
//	explicit A(int a)
//	{
//		cout << a << endl;
//	}
//};
//int main() {
//	A a1(10);
//	//A a2 = 10;
//	string s = "100.2";
//	double ret = stod(s);
//	cout << ret << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//class A {
//public:
//	A() = default;
//	A(int&& a) {
//		cout << a << endl;
//	}
//};
//int main() {
//	int val = 123;
//	//A a(val);
//	A a;
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//class A final
//{
//public:
//	
//};
//class B : public A {
//
//};
//int main() {
//	
//	return 0;
//}

#include <iostream>
#include <string>
using namespace std;
int main() {
	int a = 10;
	auto func = [=](int n)->int {
		cout << a << endl;
		return n;
	};
	cout << func(23) << endl;
	return 0;
}