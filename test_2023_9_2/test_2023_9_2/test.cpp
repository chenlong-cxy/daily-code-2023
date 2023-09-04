//#include <iostream>
//using namespace std;
//int func(int a, int b) {
//	return a + b;
//}
//class A {
//public:
//	int func1(int a, int b) {
//		return a + b;
//	}
//	static int func2(int a, int b) {
//		return a + b;
//	}
//};
//int main() {
//	cout << func << endl;
//	cout << &func << endl;
//	cout << A::func2 << endl;
//	cout << &A::func2 << endl;
//
//	cout << &A::func1 << endl;
//	printf("%p\n", &A::func1);
//	return 0;
//}

//#include <iostream>
//#include <fstream>
//using namespace std;
//int main() {
//	ofstream ofile;
//	ofile.open("cppIO.txt", ofstream::out);
//	string data("cppIOTest");
//	ofile.write(data.c_str(), data.size());
//	ofile.put('!');
//	ofile.close();
//	return 0;
//}

//#include <iostream>
//#include <fstream>
//using namespace std;
//int main() {
//	ofstream ofile;
//	ofile.open("cppIO.txt", ofstream::out);
//	ofile << "testMore";
//	ofile.close();
//	return 0;
//}

//#include <iostream>
//#include <fstream>
//using namespace std;
//int main() {
//	ifstream ifile;
//	ifile.open("cppIO.txt", ifstream::in);
//	ifile.seekg(0, ifile.end); //arg2: 基地址 arg1: 相对于arg1的偏移量
//	int len = ifile.tellg();
//	ifile.seekg(0, ifile.beg);
//	char data[1000] = {'\0'};
//	ifile.read(data, len);
//	cout << data << endl;
//	ifile.close();
//	return 0;
//}

//#include <iostream>
//#include <fstream>
//using namespace std;
//int main() {
//	ifstream ifile;
//	ifile.open("cppIO.txt", ifstream::in);
//	char data[1000] = { '\0' };
//	ifile >> data;
//	cout << data << endl;
//	ifile.close();
//	return 0;
//}

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main() {
	stringstream s;
	double a = 1.2;
	s << a;
	string data;
	s >> data;
	cout << data << endl;
	s.str("");
	s.clear();
	s << "cpp" << "IO";
	cout << s.str() << endl;
	return 0;
}
