//#include <iostream>
//using namespace std;
//struct listNode {
//	int _val;
//	listNode* _prev;
//	listNode* _next;
//	~listNode() {
//		cout << "~listNode()" << endl;
//	}
//};
//int main() {
//	listNode* node1 = new listNode;
//	listNode* node2 = new listNode;
//	node1->_prev = node2;
//	node2->_next = node1;
//	//...
//	delete node1;
//	delete node2;
//	return 0;
//}

//#include <iostream>
//#include <memory>
//using namespace std;
//struct listNode {
//	int _val;
//	shared_ptr<listNode> _prev;
//	shared_ptr<listNode> _next;
//	~listNode() {
//		cout << "~listNode()" << endl;
//	}
//};
//int main() {
//	shared_ptr<listNode> node1(new listNode);
//	shared_ptr<listNode> node2(new listNode);
//	node1->_prev = node2;
//	node2->_next = node1;
//	//...
//	return 0;
//}

//#include <iostream>
//#include <memory>
//using namespace std;
//struct listNode {
//	int _val;
//	weak_ptr<listNode> _prev;
//	weak_ptr<listNode> _next;
//	~listNode() {
//		cout << "~listNode()" << endl;
//	}
//};
//int main() {
//	shared_ptr<listNode> node1(new listNode);
//	shared_ptr<listNode> node2(new listNode);
//	node1->_prev = node2;
//	node2->_next = node1;
//	//...
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class HeapOnly
//{
//public:
//	//2、提供一个获取对象的接口，并且该接口必须设置为静态成员函数
//	static HeapOnly* CreateObj()
//	{
//		return new HeapOnly;
//	}
//private:
//	//1、将构造函数设置为私有
//	HeapOnly()
//	{}
//	//3、将拷贝构造函数设置为私有，并且只声明不实现
//	//C++98
//	HeapOnly(const HeapOnly&);
//	//C++11
//	//HeapOnly(const HeapOnly&) = delete;
//};
//int main() {
//	HeapOnly* p = HeapOnly::CreateObj();
//	return 0;
//}

#include <iostream>
using namespace std;
class A {
public:
	virtual void func() {
		cout << "A" << endl;
	}
	int _a = 1;
};
class B : public A {
public:
	int _b = 2;
};
int main() {
	double a = 10.5;
	int b = static_cast<int>(a);
	cout << b << endl;

	volatile const int c = 10;
	int* d = const_cast<int*>(&c);
	*d = 20;
	cout << c << endl;
	cout << *d << endl;

	int e = 10;
	int f = reinterpret_cast<int>(&e);
	cout << f << endl;

	A* g = new A;
	A* h = new B;
	B* x = dynamic_cast<B*>(h);
	if (x == nullptr) {
		cout << "转换失败" << endl;
	}
	else {
		cout << x->_b << endl;
	}
	return 0;
}
