#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
//class Solution {
//public:
//	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
//		set<int> us;
//		for (int i = 0; i < nums.size(); i++)
//		{
//			auto iter = lower_bound(us.begin(), us.end(), max(nums[i], INT_MIN + t) - t);
//			/*
//			if(iter != us.end())
//			cout<<"debug: "<<*iter<<endl;
//			else
//			cout<<"end"<<endl;
//			*/
//			if (iter != us.end() && *iter <= min(nums[i], INT_MAX - t) + t)
//				return true;
//			us.insert(nums[i]);
//			if (i >= k)
//				us.erase(nums[i - k]);
//		}
//		return false;
//	}
//};
//class Solution {
//public:
//	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
//		unordered_map<int, int> um; //ÿ��Ͱ���ֻ��Ҫ�洢һ��������Ϊ������ֱ�ӷ���true��
//		for (int i = 0; i < nums.size(); i++)
//		{
//			long long x = nums[i]; //��ֹ����um[id-1]-x���
//			int id = getId(x, t + 1ll); //��ֹt+1���
//			if (um.count(id)) //ͬһ��Ͱ�е�������������Ȼ����
//				return true;
//			if (um.count(id - 1) && abs(um[id - 1] - x) <= t) //����Ͱ�������㣬��Ҫ�ж�
//				return true;
//			if (um.count(id + 1) && abs(um[id + 1] - x) <= t)
//				return true;
//			um[id] = x;
//			if (i >= k)
//				um.erase(getId(nums[i - k], t + 1ll));
//		}
//		return false;
//	}
//	int getId(int num, long long w)
//	{
//		if (num >= 0)
//			return num / w;
//		else
//			return (num + 1) / w - 1;
//	}
//};
int main()
{
	map<int, int> m = {
		{1,2},
		{3,4},
		{5,6}
	};
	//auto iter = lower_bound(m.begin(), m.end(), 1);
	auto iter = m.lower_bound(1);
	cout << iter->first << endl;
	cout << iter->second << endl;
	return 0;
}