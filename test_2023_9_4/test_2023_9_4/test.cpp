//#include <iostream>
//using namespace std;
//class A {
//public:
//	int a = 1;
//protected:
//	int b = 2;
//private:
//	int c = 3;
//};
//class B : private A {
//public:
//	void func() {
//		cout << a << endl;
//		cout << b << endl;
//		//cout << c << endl; //基类的private成员在派生类中不可见
//	}
//};
//int main() {
//	B().func();
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class A {
//public:
//	int _a = 1;
//};
//class B : virtual public A {
//public:
//	int _b = 2;
//};
//class C : virtual public A {
//public:
//	int _c = 3;
//};
//class D : public B, public C {
//public:
//	int _d = 4;
//};
//int main() {
//	D d;
//	cout << d._a << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//class A {
//public:
//	A(const string& name, int age)
//		:_name(name)
//		, _age(age)
//	{
//		cout << "A(const string& name, int age)" << endl;
//	}
//	A(const A& a)
//		:_name(a._name)
//		, _age(a._age)
//	{
//		cout << "A(const A& a)" << endl;
//	}
//	A& operator=(const A& a) {
//		cout << "A& operator=(const A& a)" << endl;
//		if (&a != this) {
//			_name = a._name;
//			_age = a._age;
//		}
//		return *this;
//	}
//	~A() {
//		cout << "~A()" << endl;
//	}
//private:
//	string _name;
//	int _age;
//};
//class B : public A {
//public:
//	B(const string& name, int age, int id)
//		:A(name, age)
//		, _id(id)
//	{
//		cout << "B(const string& name, int age, int id)" << endl;
//	}
//	B(const B& b)
//		:A(b)
//		, _id(b._id)
//	{
//		cout << "B(const B& b)" << endl;
//	}
//	B& operator=(const B& b) {
//		cout << "B& operator=(const B& b)" << endl;
//		if (&b != this) {
//			A::operator=(b);
//			_id = b._id;
//		}
//		return *this;
//	}
//	~B() {
//		cout << "~B()" << endl;
//	}
//private:
//	int _id;
//};
//int main() {
//	B b("lee", 12, 1);
//	B tmp("dragon", 22, 2);
//	b = tmp;
//	return 0;
//}


#include <iostream>
using namespace std;
class A {
public:
	virtual void funcA() {
		cout << "A::funcA()" << endl;
	}
	int _a = 1;
};
class B : virtual public A {
public:
	virtual void funcB() {
		cout << "B::funcB()" << endl;
	}
	int _b = 2;
};
class C : virtual public A {
public:
	virtual void funcA() {
		cout << "C::funcA()" << endl;
	}
	virtual void funcC() {
		cout << "C::funcC()" << endl;
	}
	int _c = 3;
};
class D : public B, public C {
public:
	virtual void funcD() {
		cout << "D::funcD()" << endl;
	}
	virtual void funcA() {
		cout << "D::funcA()" << endl;
	}
	int _d = 4;
};
int main() {
	//A* pa = new A;
	//A* pb = new B;
	//A* pc = new C;
	//A* pd = new D;
	//pc->funcA();
	//pd->funcA();
	A a;
	B b;
	C c;
	D d;

	return 0;
}