#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	char ch;
	cin >> ch;
	int n = 0;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	string s;
	int curLevel = 0;
	vector<string> ans;
	for (int i = 0; i < n; i++) {
		int start = v[i].find_first_not_of('-');
		int end = v[i].find_last_not_of('/');
		string str = v[i].substr(start, end - start + 1);
		int level = start;
		while (level < curLevel) {
			int pos = s.find_last_of('/');
			s = s.substr(0, pos);
			curLevel--;
		}
		s += "/";
		s += str;
		curLevel++;
		
		if (str.find(ch) != string::npos) {
			ans.push_back(s);
		}
	}
	for (const auto& e : ans) {
		cout << e << endl;
	}
	return 0;
}
