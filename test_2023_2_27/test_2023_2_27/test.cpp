#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

//��������㶨��
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) 
		:val(x)
		,left(nullptr)
		,right(nullptr) 
	{}
};

class Codec {
public:
	//�����������л�Ϊһ���ַ���
	string serialize(TreeNode* root) {
		queue<TreeNode*> q;
		q.push(root);
		string data;
		while (!q.empty()) {
			TreeNode* front = q.front();
			q.pop();
			if (front == nullptr) {
				data += "null ";
			}
			else {
				data += to_string(front->val);
				data += " ";
				q.push(front->left);
				q.push(front->right);
			}
		}
		return data;
	}

	//�����ַ��������л���������
	TreeNode* deserialize(string data) {
		vector<string> v = splitData(data);
		if (v[0] == "null")
			return nullptr;
		TreeNode* root = new TreeNode(atoi(v[0].c_str()));
		queue<TreeNode*> q;
		q.push(root);
		int index = 1;
		while (!q.empty()) {
			TreeNode* front = q.front();
			q.pop();
			if (v[index] != "null") {
				front->left = new TreeNode(atoi(v[index].c_str()));
				q.push(front->left);
			}
			index++;
			if (v[index] != "null") {
				front->right = new TreeNode(atoi(v[index].c_str()));
				q.push(front->right);
			}
			index++;
		}
		return root;
	}

private:
	//�Կո�Ϊ�ָ������ַ������в��
	vector<string> splitData(const string& data) {
		vector<string> v;
		size_t start = 0;
		size_t pos = data.find(' ', start);
		while (pos != string::npos) {
			string sub = data.substr(start, pos - start);
			v.push_back(sub);
			start = pos + 1;
			pos = data.find(' ', start);
		}
		return v;
	}
};

int main() {
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	node1->left = node2;
	node1->right = node3;
	
	node3->left = node4;
	node3->right = node5;
	string s = Codec().serialize(node1);
	TreeNode* root = Codec().deserialize(s);
	return 0;
}