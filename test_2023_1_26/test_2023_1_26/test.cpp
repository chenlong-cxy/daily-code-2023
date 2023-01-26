#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int maxProduct(vector<string>& words) {
		unordered_map<int, int> maskToLen;
		for (int i = 0; i < words.size(); i++)
		{
			string str = words[i];
			int len = str.size();
			int mask = 0;
			for (int j = 0; j < len; j++)
			{
				mask |= (1 << (str[j] - 'a'));
			}
			if (maskToLen.find(mask) == maskToLen.end())
			{
				maskToLen[mask] = len;
			}
			else
			{
				if (len > maskToLen[mask])
					maskToLen[mask] = len;
			}
		}
		int maxMul = 0;
		/*
		for(auto [i,_] : maskToLen)
		{
		for(auto [j,_] : maskToLen)
		{
		if((i&j) == 0)
		maxMul = max(maxMul, maskToLen[i]*maskToLen[j]);
		}
		}
		*/

		for (auto i = maskToLen.begin(); i != maskToLen.end(); i++)
		{
			for (auto j = maskToLen.begin(); j != maskToLen.end(); j++)
			{
				if (((i->first)&(j->first)) == 0)
					maxMul = max(maxMul, (i->second)*(j->second));
			}
		}

		return maxMul;
	}
};

int main()
{
	vector<string> words = { "abcw", "baz", "foo", "bar", "fxyz", "abcdef" };
	cout << Solution().maxProduct(words) << endl;
	return 0;
}
