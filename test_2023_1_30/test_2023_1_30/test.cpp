//#include <iostream>
//#include <string>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//	string minWindow(string s, string t) {
//		int len1 = s.size(), len2 = t.size();
//		if (len1 < len2)
//			return "";
//		for (const char& ch : t)
//			ori[ch]++;
//		int left = 0;
//		int start = 0, len = INT_MAX;
//		for (int right = 0; right < len1; right++)
//		{
//			if (ori.find(s[right]) != ori.end())
//			{
//				cnt[s[right]]++;
//			}
//			while (check())
//			{
//				if (right - left + 1 < len)
//				{
//					start = left;
//					len = right - left + 1;
//				}
//				if (ori.find(s[left]) != ori.end())
//				{
//					cnt[s[left]]--;
//				}
//				left++;
//			}
//		}
//		return s.substr(start, len);
//	}
//	bool check()
//	{
//		for (auto [key, value] : ori)
//		{
//			if (cnt[key] < value)
//				return false;
//		}
//		return true;
//	}
//private:
//	unordered_map<char, int> ori, cnt;
//};
//int main()
//{
//	cout << Solution().minWindow("a", "b") << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    bool isPalindrome(string s) {
//        if (s == "")
//            return true;
//        int left = 0, right = s.size() - 1;
//        while (left < right)
//        {
//            while (left < right && !isalpha(s[left]) && !isdigit(s[left]))
//                left++;
//            while (right > left && !isalpha(s[right]) && !isdigit(s[right]))
//                right--;
//            if (left >= right)
//                return true;
//            if (!(s[left]-s[right] == 0||(isalpha(s[left])&&isalpha(s[right])&&abs(s[left]-s[right]) == 32)))
//                return false;
//            left++;
//            right--;
//        }
//        return true;
//    }
//};
//int main()
//{
//    cout << Solution().isPalindrome("0P") << endl;
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int countSubstrings(string s) {
//        int n = s.size();
//        vector<vector<bool>> dp(n, vector<bool>(n, false));
//        for (int i = 0; i < n; i++)
//        {
//            dp[i][i] = true;
//        }
//        int count = n;
//        for (int len = 2; len <= n; len++)
//        {
//            for (int start = 0;start+len-1 < n;start++)
//            {
//                int end = start + len - 1;
//                if (len == 2)
//                {
//                    if (s[start] == s[end])
//                    {
//                        dp[start][end] = true;
//                        count++;
//                    }
//                }
//                else
//                {
//                    if (s[start] == s[end] && dp[start + 1][end - 1])
//                    {
//                        dp[start][end] = true;
//                        count++;
//                    }
//                }
//            }
//        }
//        return count;
//    }
//};
//int main()
//{
//    cout << Solution().countSubstrings("aaaaa") << endl;
//	return 0;
//}


#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int len1 = s.size(), len2 = t.size();
        if (len1 < len2)
            return "";
        for (const char& ch : t)
            ori[ch]++;
        string tmp;
        int index = 0;
        for (int i = 0; i < len1; i++)
        {
            if (ori.find(s[i]) != ori.end())
            {
                tmp += s[i];
                um[index] = i;
                index++;
            }
        }
        int left = 0;
        int start = 0, len = INT_MAX;
        for (int right = 0; right < tmp.size(); right++)
        {
            cnt[tmp[right]]++;
            while (check())
            {
                int a = um[left], b = um[right];
                if (b - a + 1 < len)
                {
                    start = a;
                    len = b - a + 1;
                }
                cnt[tmp[left]]--;
                left++;
            }
        }
        if (len == INT_MAX)
            return "";
        return s.substr(start, len);
    }
    bool check()
    {
        for (auto [key, value] : ori)
        {
            if (cnt[key] < value) //不存在会插入<key, 0>
                return false;
        }
        return true;
    }
private:
    unordered_map<char, int> ori, cnt;
    unordered_map<int, int> um;
};
int main()
{
    cout << Solution().minWindow("wegdtzwabazduwwdysdetrrctotpcepalxdewzezbfewbabbseinxbqqplitpxtcwwhuyntbtzxwzyaufihclztckdwccpeyonumbpnuonsnnsjscrvpsqsftohvfnvtbphcgxyumqjzltspmphefzjypsvugqqjhzlnylhkdqmolggxvneaopadivzqnpzurmhpxqcaiqruwztroxtcnvhxqgndyozpcigzykbiaucyvwrjvknifufxducbkbsmlanllpunlyohwfsssiazeixhebipfcdqdrcqiwftutcrbxjthlulvttcvdtaiwqlnsdvqkrngvghupcbcwnaqiclnvnvtfihylcqwvderjllannflchdklqxidvbjdijrnbpkftbqgpttcagghkqucpcgmfrqqajdbynitrbzgwukyaqhmibpzfxmkoeaqnftnvegohfudbgbbyiqglhhqevcszdkokdbhjjvqqrvrxyvvgldtuljygmsircydhalrlgjeyfvxdstmfyhzjrxsfpcytabdcmwqvhuvmpssingpmnpvgmpletjzunewbamwiirwymqizwxlmojsbaehupiocnmenbcxjwujimthjtvvhenkettylcoppdveeycpuybekulvpgqzmgjrbdrmficwlxarxegrejvrejmvrfuenexojqdqyfmjeoacvjvzsrqycfuvmozzuypfpsvnzjxeazgvibubunzyuvugmvhguyojrlysvxwxxesfioiebidxdzfpumyon", "ozgzyywxvtublcl") << endl;
	return 0;
}
