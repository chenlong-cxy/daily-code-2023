//#include <iostream>
//#include <vector>
//using namespace std;
////nums�������Ӽ�
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
//		tmp.pop_back(); //����
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


////����k��Ԫ�ص����
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
//		if (tmp.size() + (n - cur + 1) < k) //��֦
//			return;
//		//if(cur > n) //��ʡ��
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
//		//���ó�1-n����С��k����
//		vector<int> tmp;
//		for (int i = 0; i < k; i++)
//			tmp.push_back(i + 1);
//		tmp.push_back(n + 1); //��n+1�ŵ�ĩβ�����ں����Ƚ�
//		int j = 0;
//		while (j < k) { //���ڲ�while��Ϊj < k���˳�ѭ��ʱ��˵�������зŵ��Ѿ�������k�����ˣ�����ѭ��
//			ans.emplace_back(tmp.begin(), tmp.begin() + k);
//			j = 0;
//			while (j < k&&tmp[j] + 1 == tmp[j + 1]) {
//				tmp[j] = j + 1; //�����������С�������Ǵ�1��ʼ�ģ����൱��û���������൱�ڽ�1110��Ϊ10011
//				j++;
//			}
//			tmp[j]++;
//		}
//		return ans;
//	}
//};


////�����ظ�ѡ��Ԫ�ص����
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
//		dfs(candidates, target, index + 1); //��Ҫindexλ�õ�����
//		if (target - candidates[index] >= 0) {
//			tmp.push_back(candidates[index]);
//			dfs(candidates, target - candidates[index], index); //���ظ�ʹ��indexλ�õ�����
//			tmp.pop_back(); //����
//		}
//	}
//private:
//	vector<vector<int>> ans;
//	vector<int> tmp;
//};
