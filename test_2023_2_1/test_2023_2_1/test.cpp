#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return;
		//1������ָ��Ѱ���м���
		ListNode* fast = head, *slow = head, *end = nullptr;
		while (fast&&fast->next)
		{
			fast = fast->next->next;
			end = slow;
			slow = slow->next;
		}
		//2����ת��벿������
		ListNode* prev = nullptr, *cur = slow;
		end->next = nullptr; //ǰ�벿�ֱ�Ϊ�ÿ�
		while (cur)
		{
			ListNode* next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		//3���ϲ���������
		cur = head;
		while (cur&&prev)
		{
			ListNode* next1 = cur->next, *next2 = prev->next;
			cur->next = prev;
			prev->next = next1;
			cur = next1;
			prev = next2;
		}
	}
};
int main()
{
	ListNode node1(1), node2(2), node3(3), node4(4), node5(5);
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	Solution().reorderList(&node1);
	return 0;
}