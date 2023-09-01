//#include <iostream>
//using namespace std;
////extern "C" {
////	int Add(int a, int b) {
////		return a + b;
////	}
////	double Add(double a, double b) {
////		return a + b;
////	}
////}
//extern "C" int Add(int a, int b) {
//	return a + b;
//}
//extern "C" double Add(double a, double b) {
//	return a + b;
//}
//int main() {
//	cout << Add(1, 2) << endl;
//	cout << Add(1.1, 2.2) << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//	int a = 10;
//	int& b = a;
//	b = 20;
//	cout << a << endl;
//	cout << b << endl;
//	cout << &a << endl;
//	cout << &b << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//inline int func(int n) { //inline只是一个建议
//	if (n == 1)
//		return 1;
//	return func(n-1) + 1;
//}
//int main() {
//	int ret = func(10);
//	return 0;
//}

//#include <iostream>
//#include "inline.h"
//using namespace std;
//int main() {
//	int ret = func(10);
//	cout << ret << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//inline int func(int n) { //inline中可以有循环
//	int ret = 0;
//	while (n--) {
//		ret += n;
//	}
//	return ret;
//}
//int main() {
//	int ret = func(10);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class A {
//public:
//	int func(int n) {
//		return _a + n;
//	}
//private:
//	int _a = 2;
//};
//int main() {
//	A a;
//	cout << a.func(10) << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class A {
//public:
//	A() = default;
//	//A(const A& a)
//	//	:_a(a._a)
//	//{}
//	A(A a)
//		:_a(a._a)
//	{}
//	int _a = 10;
//};
//int main() {
//	A a;
//	a._a = 20;
//	A a2(a);
//	cout << a2._a << endl;
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class A {
//public:
//	A(int n)
//		:b(n++)
//		, c(n++)
//		, a(n++)
//	{}
//	int a;
//	int b;
//	int c;
//};
//int main() {
//	A a(10);
//	cout << a.a << endl;
//	cout << a.b << endl;
//	cout << a.c << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class A {
//public:
//	int a;
//	int b;
//	static int c;
//};
//int A::c = 10;
//int main() {
//	A a;
//	cout << a.c << endl;
//	cout << A().c << endl;
//	cout << A::c << endl;
//	cout << sizeof(A) << endl;
//	return 0;
//}

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
			//cout << "string()" << endl;

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
			//cout << "string(const string& s)" << endl;
			strcpy(_str, s._str);
		}
		//拷贝赋值函数
		string& operator=(const string& s) {
			//cout << "string& operator=(string s)" << endl;
			if (this != &s) {
				string tmp(s);
				swap(tmp);
			}
			return *this;
		}
		//析构函数
		~string() {
			//cout << "~string()" << endl;
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
				_str[i+1] = _str[i];
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
//int main() {
//	cl::string s("dragon");
//	auto func = [](const cl::string& s) {
//		cout << "字符串: " << s << endl;
//		cout << "size: " << s.size() << endl;
//		cout << "capacity: " << s.capacity() << endl;
//	};
//	func(s);
//	s.push_back('x');
//	func(s);
//	cl::string tmp(s);
//	func(tmp);
//	tmp.push_back('1');
//	tmp.push_back('2');
//	tmp.push_back('3');
//	tmp.push_back('4');
//	tmp.push_back('5');
//	func(tmp);
//	return 0;
//}
#include <string>
int main() {
	std::string s("dragon");
	auto func = [](const std::string& s) {
		cout << "字符串: " << s << endl;
		cout << "size: " << s.size() << endl;
		cout << "capacity: " << s.capacity() << endl;
	};
	func(s);
	s.push_back('x');
	func(s);
	std::string tmp(s);
	func(tmp);
	tmp.push_back('1');
	tmp.push_back('2');
	tmp.push_back('3');
	tmp.push_back('4');
	tmp.push_back('5');
	tmp.push_back('6');
	tmp.push_back('7');
	tmp.push_back('8');
	func(tmp);
	return 0;
}
