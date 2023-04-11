#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
const vector<int> getMonthDays = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool Judge(const string& s) { //20230411
	int month = stoi(s.substr(4, 2));
	int day = stoi(s.substr(6, 2));
	if (month >= 1 && month <= 12) {
		int m = getMonthDays[month];
		if (day >= 1 && day <= m) {
			return true;
		}
	}
	return false;
}
void dfs(string& s, int cur, int len, string& tmp, unordered_set<string>& ans) {
	if (len == 8) {
		if (Judge(tmp)) {
			ans.insert(tmp);
			//cout << tmp << endl;
		}
		return;
	}
	if (cur == s.size())
		return;
	if (len < 4) {
		if (len == 0 && s[cur] == '2') {
			tmp.push_back(s[cur]);
			dfs(s, cur + 1, len + 1, tmp, ans);
			tmp.pop_back();
		}
		if (len == 1 && s[cur] == '0') {
			tmp.push_back(s[cur]);
			dfs(s, cur + 1, len + 1, tmp, ans);
			tmp.pop_back();
		}
		if (len == 2 && s[cur] == '2') {
			tmp.push_back(s[cur]);
			dfs(s, cur + 1, len + 1, tmp, ans);
			tmp.pop_back();
		}
		if (len == 3 && s[cur] == '3') {
			tmp.push_back(s[cur]);
			dfs(s, cur + 1, len + 1, tmp, ans);
			tmp.pop_back();
		}
	}
	else {
		tmp.push_back(s[cur]);
		dfs(s, cur + 1, len + 1, tmp, ans);
		tmp.pop_back();
	}
	dfs(s, cur + 1, len, tmp, ans);
}
int main() {
	string s = "5686916124919823647759503875815861830379270588570991944686338516346707827689565614010094809128502533";
	unordered_set<string> ans;
	string tmp;
	dfs(s, 0, 0, tmp, ans);
	cout << ans.size() << endl;
	return 0;
}