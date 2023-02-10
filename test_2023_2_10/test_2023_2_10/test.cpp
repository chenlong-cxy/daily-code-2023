#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//class Solution {
//public:
//	int pathSum(TreeNode* root, long long targetSum) {
//		if (root == nullptr)
//			return 0;
//		int ret = rootSum(root, targetSum);
//		ret += pathSum(root->left, targetSum);
//		ret += pathSum(root->right, targetSum);
//		return ret;
//	}
//	int rootSum(TreeNode* root, long long targetSum) {
//		if (root == nullptr)
//			return 0;
//		int ret = 0;
//		if (root->val == targetSum)
//			ret++;
//		ret += rootSum(root->left, targetSum - root->val);
//		ret += rootSum(root->right, targetSum - root->val);
//		return ret;
//	}
//private:
//};
class Solution {
public:
	int pathSum(TreeNode* root, long long targetSum) {
		prefix[0] = 1;
		return dfs(root, 0, targetSum);
	}
	int dfs(TreeNode* root, long long cur, int targetSum)
	{
		if (root == nullptr)
			return 0;
		cur += root->val;
		int ret = 0;
		if (prefix.count(cur - targetSum))
			ret = prefix[cur - targetSum];
		prefix[cur]++;
		ret += dfs(root->left, cur, targetSum);
		ret += dfs(root->right, cur, targetSum);
		prefix[cur]--;
		return ret;
	}
private:
	unordered_map<long long, int> prefix;
};
int main()
{
	TreeNode* node1 = new TreeNode(10);
	TreeNode* node2 = new TreeNode(5);
	TreeNode* node3 = new TreeNode(-3);
	TreeNode* node4 = new TreeNode(3);
	TreeNode* node5 = new TreeNode(2);
	TreeNode* node6 = new TreeNode(11);
	TreeNode* node7 = new TreeNode(3);
	TreeNode* node8 = new TreeNode(-2);
	TreeNode* node9 = new TreeNode(1);

	node1->left = node2;
	node1->right = node3;

	node2->left = node4;
	node2->right = node5;

	node3->right = node6;

	node4->left = node7;
	node4->right = node8;

	node5->right = node9;

	cout << Solution().pathSum(node1, 8) << endl;

	return 0;
}