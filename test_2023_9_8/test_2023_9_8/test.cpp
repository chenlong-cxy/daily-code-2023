#include <iostream>
#include <deque>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

//class Solution {
//public:
//	int getWaterByRegion(const vector<int>& height, int start, int end) {
//		int waterLevel = min(height[start], height[end]), water = 0;
//		for (int i = start + 1; i <= end - 1; i++) {
//			if (height[i] < waterLevel)
//				water += (waterLevel - height[i]);
//		}
//		return water;
//	}
//	int trap(vector<int>& height) {
//		int maxWater = 0;
//		int start = 0;
//		while (start < height.size()) {
//			int end = start + 1;
//			deque<int> deq;
//			bool up = false;
//			while (end < height.size() && height[end] < height[start]) {
//				if (height[end] > height[end - 1]) {
//					up = true;
//				}
//				else if (height[end] < height[end - 1] && up == true) {
//					while (!deq.empty() && height[deq.back()] <= height[end - 1]) {
//						deq.pop_back();
//					}
//					deq.push_back(end - 1);
//					up = false;
//				}
//				end++;
//			}
//			if (up == true) {
//				while (!deq.empty() && height[deq.back()] <= height[end - 1]) {
//					deq.pop_back();
//				}
//				deq.push_back(end - 1);
//			}
//			if (end == height.size()) { //根据队列里面的数据计算
//				while (!deq.empty()) {
//					int qEnd = deq.front();
//					deq.pop_front();
//					int waterLevel = min(height[start], height[qEnd]);
//					maxWater += getWaterByRegion(height, start, qEnd);
//					start = qEnd;
//				}
//			}
//			else { //根据start和end计算
//				maxWater += getWaterByRegion(height, start, end);
//			}
//			start = end;
//		}
//		return maxWater;
//	}
//};
//class Solution {
//public:
//	int trap(vector<int>& height) {
//		int n = height.size();
//		vector<int> leftMax(n, 0), rightMax(n, 0);
//		leftMax[0] = height[0], rightMax[n - 1] = height[n - 1];
//		for (int i = 1; i < n; i++) {
//			leftMax[i] = max(height[i], leftMax[i - 1]);
//		}
//		for (int i = n - 2; i >= 0; i--) {
//			rightMax[i] = max(height[i], rightMax[i + 1]);
//		}
//		int maxWater = 0;
//		for (int i = 0; i < n; i++) {
//			maxWater += (min(leftMax[i], rightMax[i]) - height[i]);
//		}
//		return maxWater;
//	}
//};
class Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		int result;
		stack<int> st;
		for (int i = 0; i < n; i++) {
			while (!st.empty() && height[i] > height[st.top()]) {
				int top = st.top();
				st.pop();
				if (st.empty()) {
					break;
				}
				int left = st.top();
				int w = i - left - 1;
				int h = min(height[left], height[i]) - height[top];
				result += w * h;
			}
			st.push(i);
		}
		return result;
	}
};
class Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		int result = 0;
		int left = 0, right = n - 1, leftMax = 0, rightMax = 0;
		while (left < right) {
			leftMax = max(leftMax, height[left]);
			rightMax = max(rightMax, height[right]);
			if (leftMax < rightMax) {
				result += (leftMax - height[left]);
				left++;
			}
			else {
				result += (rightMax - height[right]);
				right--;
			}
		}
		return result;
	}
};
int main() {
	vector<int> v = { 4, 3, 3, 3, 1, 5, 9, 9, 0, 4, 3, 4, 7 };
	cout << Solution().trap(v) << endl;
	return 0;
}
