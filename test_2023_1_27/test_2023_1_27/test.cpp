#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++)
		{
			if (i != 0 && nums[i] == nums[i - 1])
				continue;
			vector<vector<int>> ret = twoSum(nums, i + 1, nums.size() - 1, -nums[i]);
			if (ret.size() == 0)
				continue;
			for (int j = 0; j < ret.size(); j++)
			{
				ans.push_back({ nums[i], nums[ret[j][0]], nums[ret[j][1]] });
			}
		}
		return ans;
	}
	vector<vector<int>> twoSum(vector<int>& nums, int left, int right, int target)
	{
		vector<vector<int>> ans;
		while (left < right)
		{
			int sum = nums[left] + nums[right];
			if (sum > target)
			{
				right--;
				while (right > left&&nums[right] == nums[right + 1])
					right--;
			}
			else if (sum < target)
			{
				left++;
				while (left < right&&nums[left] == nums[left - 1])
					left++;
			}
			else
			{
				ans.push_back({ left, right });
				right--;
				left++;
				while (right > left&&nums[right] == nums[right + 1])
					right--;
				while (left < right&&nums[left] == nums[left - 1])
					left++;
			}
		}
		return ans;
	}
};
int main()
{
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> ret = Solution().threeSum(nums);
	for (auto a : ret)
	{
		for (auto e : a)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	return 0;
}