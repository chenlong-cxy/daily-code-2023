//#include <iostream>
//#include <vector>
//using namespace std;
////nums的所有子集
//class Solution {
//public:
//	vector<vector<int>> subsets(vector<int>& nums) {
//		vector<vector<int>> ans;
//		int n = nums.size();
//		for (int mask = 0; mask < (1 << n); mask++) {
//			vector<int> tmp;
//			for (int i = 0; i < n; i++) {
//				if (mask&(1 << i))
//					tmp.push_back(nums[i]);
//			}
//			ans.push_back(tmp);
//		}
//		return ans;
//	}
//};
//class Solution {
//public:
//	vector<vector<int>> subsets(vector<int>& nums) {
//		dfs(nums, 0, nums.size());
//		return ans;
//	}
//	void dfs(vector<int>& nums, int cur, int n) {
//		if (cur == n) {
//			ans.push_back(tmp);
//			return;
//		}
//		tmp.push_back(nums[cur]);
//		dfs(nums, cur + 1, n);
//		tmp.pop_back(); //回溯
//		dfs(nums, cur + 1, n);
//	}
//private:
//	vector<int> tmp;
//	vector<vector<int>> ans;
//};
//int main()
//{
//
//	return 0;
//}


////含有k个元素的组合
//class Solution {
//public:
//	vector<vector<int>> combine(int n, int k) {
//		dfs(1, n, k);
//		return ans;
//	}
//	void dfs(int cur, int n, int k) {
//		if (tmp.size() == k) {
//			ans.push_back(tmp);
//			return;
//		}
//		if (tmp.size() + (n - cur + 1) < k) //剪枝
//			return;
//		//if(cur > n) //可省略
//		//    return;
//		tmp.push_back(cur);
//		dfs(cur + 1, n, k);
//		tmp.pop_back();
//		dfs(cur + 1, n, k);
//	}
//private:
//	vector<vector<int>> ans;
//	vector<int> tmp;
//};
//class Solution {
//public:
//	vector<vector<int>> combine(int n, int k) {
//		vector<vector<int>> ans;
//		//先拿出1-n中最小的k个数
//		vector<int> tmp;
//		for (int i = 0; i < k; i++)
//			tmp.push_back(i + 1);
//		tmp.push_back(n + 1); //将n+1放到末尾，用于后续比较
//		int j = 0;
//		while (j < k) { //当内部while因为j < k而退出循环时，说明数组中放的已经是最大的k个数了，结束循环
//			ans.emplace_back(tmp.begin(), tmp.begin() + k);
//			j = 0;
//			while (j < k&&tmp[j] + 1 == tmp[j + 1]) {
//				tmp[j] = j + 1; //如果数组中最小的数就是从1开始的，则相当于没做；否则相当于将1110变为10011
//				j++;
//			}
//			tmp[j]++;
//		}
//		return ans;
//	}
//};


////允许重复选择元素的组合
//class Solution {
//public:
//	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//		dfs(candidates, target, 0);
//		return ans;
//	}
//	void dfs(vector<int>& candidates, int target, int index) {
//		if (target == 0) {
//			ans.push_back(tmp);
//			return;
//		}
//		if (index == candidates.size())
//			return;
//		dfs(candidates, target, index + 1); //不要index位置的数字
//		if (target - candidates[index] >= 0) {
//			tmp.push_back(candidates[index]);
//			dfs(candidates, target - candidates[index], index); //可重复使用index位置的数字
//			tmp.pop_back(); //回溯
//		}
//	}
//private:
//	vector<vector<int>> ans;
//	vector<int> tmp;
//};
