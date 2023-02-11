#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//二叉树中的中序后继
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};

//class Solution {
//public:
//	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
//		TreeNode* cur = root;
//		TreeNode* ans = nullptr;
//		while (cur)
//		{
//			if (p->val < cur->val)
//			{
//				ans = cur;
//				cur = cur->left;
//			}
//			else if (p->val > cur->val)
//			{
//				cur = cur->right;
//			}
//			else
//			{
//				cur = cur->right;
//				while (cur)
//				{
//					ans = cur;
//					cur = cur->left;
//				}
//			}
//		}
//		return ans;
//	}
//};
//class Solution {
//public:
//	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
//		stack<TreeNode*> st;
//		TreeNode* cur = root, *prev = nullptr;
//		while (!st.empty() || cur != nullptr)
//		{
//			//将左路结点push到栈中
//			while (cur)
//			{
//				st.push(cur);
//				cur = cur->left;
//			}
//			cur = st.top();
//			st.pop();
//			if (prev == p)
//				break;
//			prev = cur;
//			cur = cur->right;
//		}
//		return cur;
//	}
//};
//class Solution {
//public:
//	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
//		TreeNode* ans = nullptr;
//		if (p->right) //p不为空则后继节点一定是p的右子树的最左节点
//		{
//			ans = p->right;
//			while (ans->left)
//				ans = ans->left;
//			return ans;
//		}
//		TreeNode* cur = root;
//		while (cur)
//		{
//			if (cur->val > p->val)
//			{
//				ans = cur;
//				cur = cur->left;
//			}
//			else
//			{
//				cur = cur->right;
//			}
//		}
//		return ans;
//	}
//};

//所有大于等于该节点的值之和
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
//	TreeNode* convertBST(TreeNode* root) {
//		rinorder(root);
//		return root;
//	}
//	void rinorder(TreeNode* root)
//	{
//		if (root == nullptr)
//			return;
//		rinorder(root->right);
//		data += root->val;
//		root->val = data;
//		rinorder(root->left);
//	}
//private:
//	int data = 0;
//};


//二叉搜索树迭代器
//class BSTIterator {
//public:
//	BSTIterator(TreeNode* root) {
//		inorder(root);
//	}
//
//	int next() {
//		return arr[index++];
//	}
//
//	bool hasNext() {
//		return index < arr.size();
//	}
//private:
//	void inorder(TreeNode* root)
//	{
//		if (root == nullptr)
//			return;
//		inorder(root->left);
//		arr.push_back(root->val);
//		inorder(root->right);
//	}
//	vector<int> arr;
//	int index = 0;
//};
class BSTIterator {
public:
	BSTIterator(TreeNode* root)
		:cur(root)
	{}

	int next() {
		while (cur != nullptr)
		{
			st.push(cur);
			cur = cur->left;
		}
		cur = st.top();
		st.pop();
		int ret = cur->val;
		cur = cur->right;
		return ret;
	}

	bool hasNext() {
		return !st.empty() || cur != nullptr;
	}
private:
	TreeNode* cur;
	stack<TreeNode*> st;
};
int main()
{
	TreeNode* node1 = new TreeNode(4);
	TreeNode* node2 = new TreeNode(1);
	TreeNode* node3 = new TreeNode(6);
	TreeNode* node4 = new TreeNode(0);
	TreeNode* node5 = new TreeNode(2);
	TreeNode* node6 = new TreeNode(5);
	TreeNode* node7 = new TreeNode(7);
	TreeNode* node8 = new TreeNode(3);
	TreeNode* node9 = new TreeNode(8);

	node1->left = node2;
	node1->right = node3;

	node2->left = node4;
	node2->right = node5;

	node3->left = node6;
	node3->right = node7;

	node5->right = node8;
	node7->right = node9;
	Solution().convertBST(node1);
	return 0;
}