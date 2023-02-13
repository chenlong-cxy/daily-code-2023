#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Test{
	static bool cmp(pair<int, int>& m, pair<int, int>& n)
	{
		return m.second > n.second;
	}
public:
	void Print()
	{
		cout << typeid(decltype(cmp)).name() << endl;
		cout << typeid(decltype(&cmp)).name() << endl;
	}
};
//class Solution {
//public:
//    vector<int> topKFrequent(vector<int>& nums, int k) {
//        unordered_map<int, int> um;
//        for (auto num : nums)
//            um[num]++;
//        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> heap(cmp); //小堆
//        for (auto [num, count] : um)
//        {
//            if (heap.size() == k)
//            {
//                if (count > heap.top().second)
//                {
//                    heap.pop();
//                    heap.emplace(num, count);
//                }
//            }
//            else
//            {
//                heap.emplace(num, count);
//            }
//        }
//        vector<int> ans;
//        while (!heap.empty())
//        {
//            ans.push_back(heap.top().first);
//            heap.pop();
//        }
//        return ans;
//    }
//    static bool cmp(pair<int, int>& m, pair<int, int>& n)
//    {
//        return m.second > n.second;
//    }
//};
//class Solution {
//public:
//    vector<int> topKFrequent(vector<int>& nums, int k) {
//        unordered_map<int, int> um;
//        for (auto& num : nums)
//            um[num]++;
//        vector<pair<int, int>> v;
//        for (auto [num, count] : um)
//            v.emplace_back(num, count);
//        vector<int> ret;
//        qsort(v, 0, v.size() - 1, ret, k);
//        return ret;
//    }
//    void qsort(vector<pair<int, int>>& v, int start, int end, vector<int>& ret, int k)
//    {
//        //前后指针法排降序
//        int keyIndex = rand() % (end - start + 1) + start;
//        int keyCount = v[keyIndex].second;
//        swap(v[start], v[keyIndex]);
//        int index = start;
//        for (int i = start + 1; i <= end; i++)
//        {
//            if (v[i].second >= keyCount)
//            {
//                swap(v[index + 1], v[i]);
//                index++;
//            }
//        }
//        swap(v[start], v[index]);
//
//        if (k < index - start + 1)
//        {
//            qsort(v, start, index, ret, k);
//        }
//        else
//        {
//            for (int i = start; i <= index; i++)
//                ret.push_back(v[i].first);
//            if (k > index - start + 1)
//                qsort(v, index + 1, end, ret, k - (index - start + 1));
//        }
//    }
//};
int main()
{
	Test t;
	t.Print();
	return 0;
}