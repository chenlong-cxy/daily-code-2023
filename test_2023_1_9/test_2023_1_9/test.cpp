//#include <iostream>
//#include <vector>
//#include <string>
//#include <queue>
//using namespace std;
//
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//class Codec {
//public:
//
//	// Encodes a tree to a single string.
//	string serialize(TreeNode* root) {
//		queue<TreeNode*> q;
//		q.push(root);
//		string str;
//		while (!q.empty())
//		{
//			TreeNode* front = q.front();
//			q.pop();
//			if (front != nullptr)
//			{
//				q.push(front->left);
//				q.push(front->right);
//				str += to_string(front->val);
//				str += " ";
//			}
//			else
//			{
//				str += "null ";
//			}
//		}
//		return str;
//	}
//
//	// Decodes your encoded data to tree.
//	TreeNode* deserialize(string data) {
//		vector<string> dataList = getData(data);
//		if (dataList.size() == 0 || dataList[0] == "null")
//			return nullptr;
//		TreeNode* root = new TreeNode(atoi(dataList[0].c_str()));
//		queue<TreeNode*> q;
//		q.push(root);
//		int index = 1;
//		while (!q.empty())
//		{
//			TreeNode* front = q.front();
//			q.pop();
//			if (dataList[index] != "null")
//			{
//				TreeNode* leftNode = new TreeNode(atoi(dataList[index].c_str()));
//				front->left = leftNode;
//				q.push(leftNode);
//			}
//			index++;
//			if (dataList[index] != "null")
//			{
//				TreeNode* rightNode = new TreeNode(atoi(dataList[index].c_str()));
//				front->right = rightNode;
//				q.push(rightNode);
//			}
//			index++;
//		}
//		return root;
//	}
//	vector<string> getData(string& data)
//	{
//		vector<string> dataList;
//		int start = 0;
//		int pos = data.find(' ');
//		while (pos != string::npos)
//		{
//			dataList.push_back(data.substr(start, pos - start));
//			start = pos + 1;
//			pos = data.find(' ', start);
//		}
//		return dataList;
//	}
//};
//
//int main()
//{
//	TreeNode* node1 = new TreeNode(1);
//	TreeNode* node2 = new TreeNode(2);
//	TreeNode* node3 = new TreeNode(3);
//	TreeNode* node4 = new TreeNode(4);
//	TreeNode* node5 = new TreeNode(5);
//	node1->left = node2;
//	node1->right = node3;
//	node3->left = node4;
//	node3->right = node5;
//	string str = Codec().serialize(node1);
//	cout << str << endl;
//	TreeNode* root = Codec().deserialize(str);
//	return 0;
//}

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	string s = "aaa";
	do
	{
		cout << s << endl;
	} while (next_permutation(s.begin(), s.end()));
	return 0;
}
