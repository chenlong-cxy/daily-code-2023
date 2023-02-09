#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		queue<TreeNode*> q;
		q.push(root);
		string data;
		while (!q.empty())
		{
			TreeNode* front = q.front();
			q.pop();
			if (front == nullptr)
			{
				data += "null ";
			}
			else
			{
				data += to_string(front->val);
				data += " ";
				q.push(front->left);
				q.push(front->right);
			}
		}
		return data;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		vector<string> v = splitString(data);
		if (v[0] == "null")
			return nullptr;
		TreeNode* root = new TreeNode(atoi(v[0].c_str()));
		queue<TreeNode*> q;
		q.push(root);
		int index = 1;
		while (!q.empty())
		{
			TreeNode* cur = q.front();
			q.pop();
			cur->left = v[index] == "null" ? nullptr : new TreeNode(atoi(v[index].c_str()));
			index++;
			cur->right = v[index] == "null" ? nullptr : new TreeNode(atoi(v[index].c_str()));
			index++;
			if (cur->left)
				q.push(cur->left);
			if (cur->right)
				q.push(cur->right);
		}
		return root;
	}
	vector<string> splitString(string data)
	{
		vector<string> v;
		size_t start = 0;
		size_t pos = data.find(' ', start);
		while (pos != string::npos)
		{
			string sub = data.substr(start, pos - start);
			v.push_back(sub);
			start = pos + 1;
			pos = data.find(' ', start);
		}
		return v;
	}
};
int main()
{
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	node1->left = node2;
	node1->right = node3;
	node3->left = node4;
	node3->right = node5;
	Codec obj;
	string data = obj.serialize(node1);
	cout << data << endl;
	TreeNode* root = obj.deserialize(data);
	return 0;
}