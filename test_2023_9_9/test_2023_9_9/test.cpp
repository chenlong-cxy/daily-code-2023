#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int n = nums.size();
		if (n < k)
			return vector<int>();
		deque<int> dq;
		for (int i = 0; i < k; i++) {
			while (!dq.empty() && dq.back() < nums[i]) {
				dq.pop_back();
			}
			dq.push_back(nums[i]);
		}
		vector<int> result;
		result.push_back(dq.front());
		for (int start = 1; start <= n - k; start++) {
			//加入滑动窗口
			while (!dq.empty() && dq.back() < nums[start + k - 1]) {
				dq.pop_back();
			}
			dq.push_back(nums[start + k - 1]);
			//移出滑动窗口
			if (dq.front() == nums[start - 1]) {
				dq.pop_front();
			}
			//滑动窗口中的最大值
			result.push_back(dq.front());
		}
		return result;
	}
};
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int n = nums.size();
		if (n < k)
			return vector<int>();
		priority_queue<pair<int, int>> pq; //建大堆
		for (int i = 0; i < k; i++) {
			pq.emplace(nums[i], i);
		}
		vector<int> result;
		result.push_back(pq.top().first);
		for (int i = k; i < n; i++) {
			pq.emplace(nums[i], i);
			while (pq.top().second <= i - k) {
				pq.pop();
			}
			result.push_back(pq.top().first);
		}
		return result;
	}
};
int main() {
	vector<int> v = { 1, 3, -1, -3, 5, 3, 6, 7 };
	vector<int> ret = Solution().maxSlidingWindow(v, 3);
	return 0;
}
