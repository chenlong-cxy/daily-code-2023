//#include <iostream>
//using namespace std;
//class A {
//	int _a = 1;
//};
//class B : virtual public A {
//	int _b = 2;
//};
//class C : virtual public A {
//	int _c = 3;
//};
//class D : public B, public C {
//	int _d = 4;
//};
//int main() {
//	D d;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class A {
//public:
//	A() {}
//	A(A* p) {
//		p->func();
//	}
//	virtual void func() {
//		cout << "A::func()" << endl;
//	}
//	int _a;
//};
//class B : public A {
//public:
//	B() {}
//	B(B* p) 
//		:A(p)
//	{
//		p->func();
//	}
//	virtual void func() {
//		cout << "B::func()" << endl;
//	}
//	int _b;
//};
//int main() {
//	B* p = new B;
//	A* p2 = new B(p);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A {
//public:
//	A() {
//		func();
//	}
//	virtual void func() {
//		cout << "call A func" << endl;
//	}
//};
//class B :public A {
//public:
//	B() {}
//	void func() override {
//		cout << "call B func" << endl;
//	}
//};
//int main() {
//	B b;
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//int func(int a) {
//	return a;
//}
//int f() {
//	return 20;
//}
//class A {
//public:
//	int func() {
//		return 1;
//	}
//	static int sfunc() {
//		return 2;
//	}
//};
//
////template<class T1, class T2>
////T1 Add(T1 a, T2 b) {
////	return a + b;
////}
//template<class T1, class T2>
//auto Add(T1 a, T2 b)->decltype(a + b) {
//	return a + b;
//}
//int main() {
//	vector<int> a = { 1, 2, 3, 4, 5 };
//	auto b = new int;
//	cout << typeid(b).name() << endl;
//	auto c = { 1, 2, 3, 4 };
//	cout << typeid(c).name() << endl;
//
//	int x = 10, y = 20;
//	decltype(x + y) d;
//	cout << typeid(d).name() << endl;
//	
//	cout << typeid(decltype(func)).name() << endl;
//	cout << typeid(decltype(func(10))).name() << endl;
//
//	cout << typeid(decltype(f)).name() << endl;
//	cout << typeid(decltype(f())).name() << endl;
//
//	cout << typeid(decltype(A::func)).name() << endl;
//	cout << typeid(decltype(A::sfunc)).name() << endl;
//
//	auto ret1 = Add(1, 2);
//	auto ret2 = Add(1.1, 2.2);
//	auto ret3 = Add(1, 2.2);
//	auto ret4 = Add(1.1, 2);
//	cout << typeid(ret1).name() << endl;
//	cout << typeid(ret2).name() << endl;
//	cout << typeid(ret3).name() << endl;
//	cout << typeid(ret4).name() << endl;
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class A {
//public:
//	explicit A(int a)
//		:_a(a)
//	{}
//	void Print() {
//		cout << _a << endl;
//	}
//	int _a;
//};
//int main() {
//	A a = 1; //error
//	a.Print();
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>
using namespace std;
namespace cl {
	class string {
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		//构造函数
		string(const char* str = "") {
			cout << "string()" << endl;

			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		//拷贝构造函数
		string(const string& s)
			:_str(new char[s._capacity + 1])
			, _size(s._size)
			, _capacity(s._capacity)
		{
			cout << "string(const string& s)" << endl;
			strcpy(_str, s._str);
		}
		//移动构造函数
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(const string&& s) -- 移动构造" << endl;
			swap(s);
		}
		//拷贝赋值函数
		string& operator=(const string& s) {
			cout << "string& operator=(const string& s)" << endl;
			if (this != &s) {
				string tmp(s);
				swap(tmp);
			}
			return *this;
		}
		//移动赋值函数
		string& operator=(string&& s) {
			cout << "string& operator=(const string&& s) -- 移动赋值" << endl;
			swap(s);
			return *this;
		}
		//析构函数
		~string() {
			cout << "~string()" << endl;
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}

		iterator begin() {
			return _str;
		}
		const_iterator begin() const {
			return _str;
		}
		iterator end() {
			return _str + _size;
		}
		const_iterator end() const {
			return _str + _size;
		}

		size_t size() const {
			return _size;
		}
		size_t capacity() const {
			return _capacity;
		}
		void resize(size_t n, char ch = '\0') {
			if (n <= _size) {
				_size = n;
				_str[_size] = '\0';
			}
			else {
				if (n > _capacity) {
					reserve(n);
				}
				for (size_t i = _size; i < n; i++) {
					_str[i] = ch;
				}
				_size = n;
				_str[_size] = '\0';
			}
		}
		void reserve(size_t n) {
			if (n > _capacity) {
				char* tmp = new char[n + 1];
				strncpy(tmp, _str, _size + 1);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		bool empty() const {
			return strcmp(_str, "") == 0;
		}

		void push_back(char ch) {
			if (_size == _capacity) {
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			_str[_size + 1] = '\0';
			_size++;
		}
		void append(const char* str) {
			size_t len = strlen(str) + _size;
			if (len > _capacity) {
				reserve(len);
			}
			strcpy(_str + _size, str);
			_size = len;
		}
		string& operator+=(char ch) {
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str) {
			append(str);
			return *this;
		}
		string& insert(size_t pos, char ch) {
			assert(pos <= _size);
			if (_size == _capacity) {
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}
			for (size_t i = _size; i >= pos; i--) {
				_str[i + 1] = _str[i];
			}
			_str[pos] = ch;
			_size++;
			return *this;
		}
		string& insert(size_t pos, const char* str) {
			assert(pos <= _size);
			size_t len = strlen(str);
			if (len > _capacity) {
				reserve(_size + len);
			}
			for (size_t i = _size; i >= pos; i--) {
				_str[i + len] = _str[i];
			}
			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}
		string& erase(size_t pos, size_t len) {
			assert(pos < _size);
			size_t n = _size - pos;
			if (len >= n) {
				_str[pos] = '\0';
				_size = pos;
			}
			else {
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			return *this;
		}
		void clear() {
			_size = 0;
			_str[_size] = '\0';
		}
		void swap(string& s) {
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}
		const char* c_str() const {
			return _str;
		}
		char& operator[](size_t i) {
			assert(i < _size);
			return _str[i];
		}
		const char& operator[](size_t i) const {
			assert(i < _size);
			return _str[i];
		}
		size_t find(char ch, size_t pos = 0) {
			assert(pos < _size);
			for (size_t i = pos; i < _size; i++) {
				if (_str[i] == ch)
					return i;
			}
			return npos;
		}
		size_t find(const char* str, size_t pos = 0) {
			assert(pos < _size);
			const char* ret = strstr(_str + pos, str);
			if (ret == nullptr) {
				return npos;
			}
			else {
				return ret - _str;
			}
		}
		size_t rfind(char ch, size_t pos = npos) {
			string tmp(*this);
			reverse(tmp.begin(), tmp.end());
			if (pos >= _size) {
				pos = _size - 1;
			}
			pos = _size - 1 - pos;
			size_t ret = find(ch, pos);
			if (ret != npos)
				return _size - 1 - ret;
			else
				return npos;
		}
		size_t rfind(const char* str, size_t pos = npos) {
			string tmp(*this);
			reverse(tmp.begin(), tmp.end());
			size_t len = strlen(str);
			char* arr = new char[len + 1];
			strcpy(arr, str);
			reverse(arr, arr + len);
			if (pos >= _size) {
				pos = _size - 1;
			}
			pos = _size - 1 - pos;
			size_t ret = find(arr, pos);
			if (ret != npos)
				return _size - ret - len;
			else
				return npos;
		}
		bool operator>(const string& s) const {
			return strcmp(_str, s._str) > 0;
		}
		bool operator<(const string& s) const {
			return strcmp(_str, s._str) < 0;
		}
		bool operator>=(const string& s) const {
			return !(*this < s);
		}
		bool operator<=(const string& s) const {
			return !(*this > s);
		}
		bool operator==(const string& s) const {
			return strcmp(_str, s._str) == 0;
		}
		bool operator!=(const string& s) const {
			return !(*this == s);
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static const size_t npos = -1;
	};
	istream& operator>>(istream& in, string& s) {
		s.clear();
		char ch = in.get();
		while (ch != '\n' && ch != ' ') {
			s += ch;
			ch = in.get();
		}
		return in;
	}
	ostream& operator<<(ostream& out, const string& s) {
		for (auto ch : s) {
			out << ch;
		}
		return out;
	}
	istream& getline(istream& in, string& s) {
		s.clear();
		char ch = in.get();
		while (ch != '\n') {
			s += ch;
			ch = in.get();
		}
		return in;
	}
}
//cl::string getString(char* str) {
//	cl::string tmp(str);
//	return tmp;
//}
//int main() {
//	cl::string ret;
//	ret = getString("dragon");
//	return 0;
//}
//void func(cl::string&& s) {
//	cout << "右值引用版本" << endl;
//	cl::string tmp(forward<cl::string>(s));
//}
//int main() {
//	func(cl::string("dragon"));
//	return 0;
//}
//void func(int& x) {
//	cout << "左值引用" << endl;
//}
//void func(const int& x) {
//	cout << "const左值引用" << endl;
//}
//void func(int&& x) {
//	cout << "右值引用" << endl;
//}
//void func(const int&& x) {
//	cout << "const右值引用" << endl;
//}
//template<class T>
//void perfectForward(T&& t) {
//	func(forward<T>(t));
//}
//int main() {
//	int a = 10;
//	perfectForward(a);
//	perfectForward(move(a));
//	const int b = 20;
//	perfectForward(b);
//	perfectForward(move(b));
//	return 0;
//}


class A {
public:
	int _a;
};
int main() {
	A a;
	cout << a._a << endl;
	return 0;
}