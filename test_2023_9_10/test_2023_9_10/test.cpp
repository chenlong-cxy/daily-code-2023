//#include <iostream>
//using namespace std;
//int main() {
//	cout << static_cast<int>('a') << endl;
//	cout << static_cast<int>('A') << endl;
//	cout << ('z' - 'A' + 1) << endl;
//	return 0;
//}


#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;
class Solution {
public:
	string minWindow(string s, string t) {
		int n = s.size(), m = t.size();
		if (n < m)
			return "";
		unordered_set<char> us(t.begin(), t.end());
		unordered_map<int, int> indexMap;
		string str;
		int index = 0;
		for (int i = 0; i < n; i++) {
			if (us.count(s[i])) {
				str.push_back(s[i]);
				indexMap[index] = i;
				index++;
			}
		}
		if (str.size() < m)
			return "";
		vector<int> record('z' - 'A' + 1, 0);
		for (int i = 0; i < m; i++) {
			record[str[i] - 'A']++;
			record[t[i] - 'A']--;
		}
		int needCh = 0;
		for (const int& count : record) {
			if (count < 0)
				needCh++;
		}
		int minStart = 0, minLen = 0;
		int left = 0, right = m - 1;
		while (needCh == 0|| right + 1 < str.size()) {
			if (needCh == 0) {
				int len = indexMap[right] - indexMap[left] + 1;
				if (minLen == 0 || len < minLen) {
					minStart = indexMap[left];
					minLen = len;
				}
				record[str[left] - 'A']--;
				if (record[str[left] - 'A'] < 0) {
					needCh++;
				}
				left++;
			}
			else if (needCh > 0) {
				right++;
				record[str[right] - 'A']++;
				if (record[str[right] - 'A'] == 0) {
					needCh--;
				}
			}
		}
		return s.substr(minStart, minLen);
	}
};
int main() {
	string s = "ADOBECODEBANC", t = "ABC";
	cout << Solution().minWindow(s, t) << endl;
	return 0;
}
