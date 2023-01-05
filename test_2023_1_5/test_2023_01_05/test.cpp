#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<int> v;
		for (int num = 1; num <= (target + 1) / 2 + 1; num++)
		{
			v.push_back(num);
		}
		int left = 0, right = 0, total = 0;
		vector<vector<int>> ans;
		while (right < v.size())
		{
			if (total < target)
			{
				total += v[right];
				right++;
			}
			else if (total > target)
			{
				total -= v[left];
				left++;
			}
			else
			{
				vector<int> tmp(v.begin() + left, v.begin() + right);
				ans.push_back(tmp);
				total -= v[left];
				left++;
			}
		}
		return ans;
	}
};
int main()
{
	vector<vector<int>> ret = Solution().findContinuousSequence(9);
	for (auto v : ret)
	{
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	return 0;
}