#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		int len1 = s1.size(), len2 = s2.size();
		if (len1 > len2)
			return false;
		vector<int> v(26, 0);
		int diff = 0;
		for (int i = 0; i < len1; i++)
		{
			v[s1[i] - 'a']--;
			v[s2[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++)
		{
			if (v[i] != 0)
				diff++;
		}
		int left = 0, right = len1;
		for (int left = 0, right = len1; right < len2; left++, right++)
		{
			if (s2[left] == s2[right])
				continue;
			if (diff == 0)
				return true;
			if (v[s2[right] - 'a'] == 0)
				diff++;
			v[s2[right] - 'a']++;
			if (v[s2[right] - 'a'] == 0)
				diff--;
			if (v[s2[left] - 'a'] == 0)
				diff++;
			v[s2[left] - 'a']--;
			if (v[s2[left] - 'a'] == 0)
				diff--;
		}
		if (diff == 0)
			return true;
		return false;
	}
};
int main()
{
	string s1 = "ab", s2 = "eidbaooo";
	cout << Solution().checkInclusion(s1, s2) << endl;
	return 0;
}