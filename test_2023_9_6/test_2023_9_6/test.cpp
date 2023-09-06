//#include <iostream>
//using namespace std;
//int main() {
//	auto a = 10, b = 1.2;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//template<class ...Args>
//void showList(Args... args) {
//	cout << sizeof...(args) << endl;
//}
//int main() {
//	showList(10);
//	showList(10, 'x');
//	showList(10, 'x', "ff");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//void showList() {
//	cout << endl;
//}
//template<class T, class ...Args>
//void showList(T value, Args... args) {
//	cout << value << " ";
//	showList(args...);
//}
//int main() {
//	showList(10);
//	showList(10, 'x');
//	showList(10, 'x', "ff");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//template<class ...Args>
//void showList(Args... args) {
//	int arr[] = { args... };
//	for (auto e : arr) {
//		cout << e << " ";
//	}
//	cout << endl;
//}
//int main() {
//	showList(10);
//	showList(10, 20);
//	showList(10, 20, 30);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//template<class T>
//void printArgs(T value) {
//	cout << value << " ";
//}
//template<class ...Args>
//void showList(Args... args) {
//	int arr[] = { (printArgs(args), 0)... };
//	cout << endl;
//}
//int main() {
//	showList(10);
//	showList(10, 'x');
//	showList(10, 'x', "ff");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int a = 10;
//int b = 20;
//auto func = [=]() {
//	cout << a + b << endl;
//};
//int main() {
//	func();
//
//	auto Swap = [](int& a, int& b) {
//		int tmp = a;
//		a = b;
//		b = tmp;
//	};
//	Swap(a, b);
//	cout << a << endl;
//	cout << b << endl;
//	return 0;
//}

//#include <iostream>
//#include <functional>
//using namespace std;
//template<class F>
//void func(F f) {
//	static int count = 0;
//	cout << &count << endl;
//}
//int Func(int a) {
//	return a;
//}
//class A {
//public:
//	int operator()(int a) {
//		return a;
//	}
//};
//int main() {
//	//func(Func);
//	//func(A());
//	//func([](int a)->int {
//	//	return a;
//	//});
//
//	function<int(int)> f1 = Func;
//	func(f1);
//	function<int(int)> f2 = A();
//	func(f2);
//	function<int(int)> f3 = [](int a)->int {
//		return a;
//	};
//	func(f3);
//	return 0;
//}

//#include <iostream>
//#include <functional>
//using namespace std;
//void func(int a, int b) {
//	cout << a << " " << b << endl;
//}
//int main() {
//	function<void(int, int)> f1 = bind(func, placeholders::_2, placeholders::_1);
//	f1(10, 20);
//	function<void(int)> f2 = bind(func, 100, placeholders::_1);
//	f2(200);
//	return 0;
//}

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <random>
#include <Windows.h>
using namespace std;
class BlockQueue {
public:
	BlockQueue(int size = 10)
		:_size(size)
	{}
	void Push(int data) {
		unique_lock<mutex> ul(_mtx);
		while (_q.size() == _size) {
			_full.wait(ul);
		}
		_q.push(data);
		_empty.notify_one();
	}
	int Pop() {
		unique_lock<mutex> ul(_mtx);
		while (_q.empty()) {
			_empty.wait(ul);
		}
		int data = _q.front();
		_q.pop();
		_full.notify_one();
		return data;
	}
private:
	queue<int> _q;
	int _size;
	mutex _mtx;
	condition_variable _empty;
	condition_variable _full;
};

int main() {
	BlockQueue bq;
	thread producer([&] {
		while (1) {
			int data = rand();
			bq.Push(data);
			Sleep(1000);
			cout << "produce a data: " << data << endl;
		}
	});
	thread consumer([&] {
		while (1) {
			int data = bq.Pop();
			cout << "consume a data: " << data << endl;
		}
	});
	producer.join();
	consumer.join();
	return 0;
}
