//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int minCut(string str) {
//	int n = str.length();
//	vector<int> dp(n + 1, 0);
//	vector<vector<bool>> palindrome(n, vector<bool>(n, false));
//
//	for (int j = 0; j < n; j++) {
//		dp[j + 1] = j;
//		for (int i = 0; i <= j; i++) {
//			if (str[i] == str[j] && (j - i <= 1 || palindrome[i + 1][j - 1])) {
//				palindrome[i][j] = true;
//				if (i == 0)
//					dp[j + 1] = 0;
//				else
//					dp[j + 1] = min(dp[j + 1], dp[i] + 1);
//			}
//		}
//	}
//
//	return dp[n];
//}
//
//int main() {
//	string str = "aabccb";
//	cout << minCut(str) << endl;  // 输出: 1
//
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//	bool judgeChar(const string& s, const string& p, int i, int j) {
//		if (i == 0)
//			return false;
//		if (p[j - 1] == '.')
//			return true;
//		return s[i - 1] == p[j - 1];
//	}
//	bool isMatch(string s, string p) {
//		int m = s.size(), n = p.size();
//		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//		dp[0][0] = 1;
//		for (int i = 0; i <= m; i++) {
//			for (int j = 1; j <= n; j++) {
//				if (p[j - 1] == '*') {
//					dp[i][j] |= dp[i][j - 2];
//					if (judgeChar(s, p, i, j - 1)) {
//						dp[i][j] |= dp[i - 1][j];
//					}
//				}
//				else {
//					if (judgeChar(s, p, i, j)) {
//						dp[i][j] |= dp[i - 1][j - 1];
//					}
//				}
//			}
//		}
//		return dp[m][n];
//	}
//};
//int main() {
//	cout << Solution().isMatch("aa", "a*") << endl;
//	return 0;
//}


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int minimumStones(int n, const string& s) {
	vector<int> stones(n);
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R')
			stones[i] = 0;
		else if (s[i] == 'G')
			stones[i] = 1;
		else
			stones[i] = 2;
	}
	vector<vector<int>> dp(n + 1, vector<int>(3, INT_MAX));

	dp[0][0] = dp[0][1] = dp[0][2] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (j != k) {
					dp[i][j] = min(dp[i][j], dp[i - 1][k] + (stones[i - 1] != j));
				}
			}
		}
	}

	return min({ dp[n][0], dp[n][1], dp[n][2] });
}

int main() {
	int n = 5;
	string s("GRRGG");

	int result = minimumStones(n, s);
	cout << "最少要取出的石头数: " << result << endl;

	return 0;
}