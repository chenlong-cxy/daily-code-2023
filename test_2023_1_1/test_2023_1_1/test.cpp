#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool verifyPostorder(vector<int>& postorder) {
		_postorder = postorder;
		vector<int> inorder(postorder);
		sort(inorder.begin(), inorder.end());
		for (int i = 0; i < inorder.size(); i++)
			_um[inorder[i]] = i;
		return decur(0, postorder.size() - 1, 0, inorder.size() - 1);
	}
	bool decur(int pLeft, int pRight, int iLeft, int iRight)
	{
		if (pLeft > pRight&&iLeft > iRight)
			return true;
		int rootVal = _postorder[pRight];
		int index = _um[rootVal];
		for (int i = pLeft; i <= pLeft + index - iLeft - 1; i++)
		{
			if (_postorder[i] > rootVal)
				return false;
		}
		for (int i = pLeft + index - iLeft; i <= pRight - 1; i++)
		{
			if (_postorder[i] < rootVal)
				return false;
		}
		return decur(pLeft, pLeft + index - iLeft - 1, iLeft, index - 1) && decur(pLeft + index - iLeft, pRight - 1, index + 1, iRight);
	}
private:
	vector<int> _postorder;
	unordered_map<int, int> _um;
};
int main()
{
	vector<int> v = { 4, 8, 6, 12, 16, 14, 10 };
	cout << Solution().verifyPostorder(v) << endl;
	return 0;
}