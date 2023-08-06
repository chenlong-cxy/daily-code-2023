//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//#include <map>
//using namespace std;
//vector<string> getString(string s) {
//	if (s == "") {
//		return vector<string>();
//	}
//	vector<string> ret;
//	int start = 0;
//	int end = s.find(' ');
//	while (end != string::npos) {
//		string tmp = s.substr(start, end - start);
//		ret.push_back(tmp);
//		start = end + 1;
//		end = s.find(' ', start);
//	}
//	ret.push_back(s.substr(start));
//	return ret;
//}
//int main() {
//	string s;
//	map<string, int> record;
//	getline(cin, s);
//	vector<string> ret = getString(s);
//	for (const auto& e : ret) {
//		record[e]++;
//	}
//	vector<pair<int, string>> v;
//	for (const auto& e : record) {
//		v.push_back(make_pair(e.second, e.first));
//	}
//	sort(v.begin(), v.end(), [](const pair<int, string>& p1, const pair<int, string>& p2) {
//		if (p1.first == p2.first) {
//			return p1.second < p2.second;
//		}
//		return p1.first > p2.first;
//	});
//	for (const auto& e : v) {
//		cout << e.second << endl;
//	}
//	return 0;
//}

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;
bool judge(int n) {
	for (int i = 2; i <= pow(n, 0.5); i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	unordered_map<int, int> um;
	for (int i = 0; i < n; i++) {
		int node = 0;
		cin >> node;
		um[node] = i;
	}
	vector<vector<int>> edges(n, vector<int>(n, 0));
	unordered_map<int, int> connectCount;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		if (judge(x + y)) {
			edges[um[x]][um[y]] = edges[um[x]][um[y]] = x + y;
			connectCount[x]++;
			connectCount[y]++;
		}
	}
	int ans = 0;
	while (1) {
		int mVal = -1, mCount = 1000000;
		for (auto e : connectCount) {
			if (e.second == 1) {
				mVal = e.first;
				mCount = e.second;
				break;
			}
			else if (e.second < mCount) {
				mVal = e.first;
				mCount = e.second;
			}
		}
		if (mVal == -1) {
			break;
		}
		ans++;
		int index = um[mVal];
		for (int i = 0; i < n; i++) {
			int val = edges[index][i];
			if (val != 0) {
				connectCount[val - mVal]--;
				if (connectCount[val - mVal] == 0) {
					connectCount.erase(val - mVal);
				}
				edges[i][index] = 0;
			}
		}
		connectCount.erase(mVal);
	}
	cout << ans << endl;
	return 0;
}