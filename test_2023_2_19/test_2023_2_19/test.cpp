//#include <iostream>
//#include <vector>
//#include <ctime>
//using namespace std;
//////�����е�k�������
////class Solution {
////public:
////	int findKthLargest(vector<int>& nums, int k) {
////		srand((unsigned int)time(nullptr));
////		return quickSort(nums, 0, nums.size() - 1, nums.size() - k);
////	}
////	int quickSort(vector<int>& nums, int left, int right, int pos) {
////		int keyIndex = rand() % (right - left + 1) + left; //�������key���±�
////		int key = nums[keyIndex];
////		swap(nums[left], nums[keyIndex]); //��key�����������
////		//��С��key��Ԫ�ؽ�����index����֮ǰ
////		int index = left;
////		for (int i = left + 1; i <= right; i++) {
////			if (nums[i] < key) {
////				swap(nums[++index], nums[i]);
////			}
////		}
////		//��index����Ԫ�غ�key��������ʱkey��ߵĶ�С��key��key�ұߵĶ����ڵ���key
////		swap(nums[index], nums[left]);
////		if (index == pos) //keyΪ��k���Ԫ��
////			return nums[index];
////		else if (index > pos) //�ұ߼�����
////			return quickSort(nums, left, index - 1, pos);
////		else //��߼�����
////			return quickSort(nums, index + 1, right, pos);
////	}
////};
//class Solution {
//public:
//	int findKthLargest(vector<int>& nums, int k) {
//		buildSmallHeap(nums, k); //��ǰk������С��
//		for (int i = k; i < nums.size(); i++) {
//			if (nums[i] < nums[0]) //С�ڶѶ���Ԫ�أ��������
//				continue;
//			swap(nums[0], nums[i]);
//			adjustDown(nums, 0, k);
//		}
//		return nums[0];
//	}
//	//����
//	void buildSmallHeap(vector<int>& nums, int heapSize) {
//		for (int i = (heapSize - 1 - 1) / 2; i >= 0; i--) {
//			adjustDown(nums, i, heapSize);
//		}
//	}
//	//�ѵ����µ����㷨
//	void adjustDown(vector<int>& nums, int parent, int heapSize) {
//		int child = parent * 2 + 1; //Ĭ�������ǽ�С��
//		while (child < heapSize) {
//			if (child + 1 < heapSize&&nums[child + 1] < nums[child]) {
//				child++;
//			}
//			if (nums[child] < nums[parent]) {
//				swap(nums[parent], nums[child]);
//				parent = child;
//				child = parent * 2 + 1;
//			}
//			else {
//				break;
//			}
//		}
//	}
//};
//int main()
//{
//	vector<int> nums = { 3, 2, 1, 5, 6, 4 };
//	cout << Solution().findKthLargest(nums, 2) << endl;
//	return 0;
//}


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
////�Զ����£���Ҫ�ݹ鿪����
//class Solution {
//public:
//	ListNode* sortList(ListNode* head) {
//		return sortList(head, nullptr);
//	}
//	ListNode* sortList(ListNode* head, ListNode* tail) {
//		if (head == nullptr) //����Ϊ��
//			return head;
//		if (head->next == tail) { //������ֻ��һ�����
//			head->next = nullptr;
//			return head;
//		}
//		ListNode* fast = head, *slow = head;
//		while (fast != tail) {
//			slow = slow->next;
//			fast = fast->next;
//			if (fast != tail)
//				fast = fast->next;
//		}
//		return merge(sortList(head, slow), sortList(slow, tail));
//	}
//	//������������й鲢����
//	ListNode* merge(ListNode* list1, ListNode* list2) {
//		ListNode* head = new ListNode;
//		ListNode* cur = head;
//		ListNode* cur1 = list1, *cur2 = list2;
//		while (cur1 != nullptr&&cur2 != nullptr) {
//			if (cur1->val < cur2->val) {
//				cur->next = cur1;
//				cur1 = cur1->next;
//			}
//			else {
//				cur->next = cur2;
//				cur2 = cur2->next;
//			}
//			cur = cur->next;
//		}
//		if (cur1 != nullptr) {
//			cur->next = cur1;
//		}
//		if (cur2 != nullptr) {
//			cur->next = cur2;
//		}
//		return head->next;
//	}
//};
//
////�Ե����ϣ��ռ临�Ӷ�O(1)��
//class Solution {
//public:
//	ListNode* sortList(ListNode* head) {
//		if (head == nullptr)
//			return head;
//		//ͳ�������еĽ�����
//		int length = 0;
//		ListNode* cur = head;
//		while (cur) {
//			length++;
//			cur = cur->next;
//		}
//		ListNode* tmpHead = new ListNode;
//		tmpHead->next = head;
//		for (int sortLength = 1; sortLength < length; sortLength *= 2) { //ÿ�κϲ��Ľ���������
//			ListNode* prev = tmpHead, *curr = tmpHead->next;
//			while (curr) {
//				//����1
//				ListNode* head1 = curr;
//				for (int i = 1; i < sortLength&&curr->next; i++) {
//					curr = curr->next;
//				}
//				//����2
//				ListNode* head2 = curr->next;
//				curr->next = nullptr; //����1��β�ÿ�
//				curr = head2; //����curr��head2
//				for (int i = 1; i < sortLength&&curr; i++) {
//					curr = curr->next;
//				}
//				if (curr) { //��Ҫ����currλ��
//					ListNode* nextNode = curr->next;
//					curr->next = nullptr; //����2��β�ÿ�
//					curr = nextNode;
//				}
//				//�ϲ�����1������2
//				ListNode* merged = merge(head1, head2);
//				prev->next = merged; //����ǰ�ϲ�������֮ǰ��������������
//				while (prev->next) //�ҵ���ǰ�ϲ������β��㣬��������һ�κϲ��������������
//					prev = prev->next;
//			}
//		}
//		return tmpHead->next;
//	}
//	//�ϲ�������������
//	ListNode* merge(ListNode* list1, ListNode* list2) {
//		ListNode* head = new ListNode;
//		ListNode* cur = head;
//		ListNode* cur1 = list1, *cur2 = list2;
//		while (cur1&&cur2) {
//			if (cur1->val < cur2->val) {
//				cur->next = cur1;
//				cur1 = cur1->next;
//			}
//			else {
//				cur->next = cur2;
//				cur2 = cur2->next;
//			}
//			cur = cur->next;
//		}
//		if (cur1)
//			cur->next = cur1;
//		if (cur2)
//			cur->next = cur2;
//		return head->next;
//	}
//};

////�ϲ������еĶ����������
//class Solution {
//public:
//	ListNode* mergeKLists(vector<ListNode*>& lists) {
//		return mergeList(lists, 0, lists.size() - 1);
//	}
//	ListNode* mergeList(vector<ListNode*>& lists, int left, int right) {
//		if (left == right)
//			return lists[left];
//		if (left > right)
//			return nullptr;
//		int mid = (left + right) / 2;
//		return mergeTwoList(mergeList(lists, left, mid), mergeList(lists, mid + 1, right));
//	}
//	ListNode* mergeTwoList(ListNode* list1, ListNode* list2) {
//		ListNode* head = new ListNode;
//		ListNode* cur = head;
//		ListNode* cur1 = list1, *cur2 = list2;
//		while (cur1&&cur2) {
//			if (cur1->val < cur2->val) {
//				cur->next = cur1;
//				cur1 = cur1->next;
//			}
//			else {
//				cur->next = cur2;
//				cur2 = cur2->next;
//			}
//			cur = cur->next;
//		}
//		if (cur1)
//			cur->next = cur1;
//		if (cur2)
//			cur->next = cur2;
//		return head->next;
//	}
//};
//
//class Solution {
//public:
//	struct Front {
//		int val;
//		ListNode* ptr;
//		// bool operator<(const Front& f) const{
//		//     return val > f.val;
//		// }
//	};
//	struct cmp {
//		bool operator()(const Front& m, const Front& n) {
//			return m.val > n.val;
//		}
//	};
//	ListNode* mergeKLists(vector<ListNode*>& lists) {
//		priority_queue<Front, vector<Front>, cmp> pq;
//		//��ÿ������ĵ�һ��������С����
//		for (auto list : lists)
//		if (list)
//			pq.push({ list->val, list });
//		ListNode* head = new ListNode;
//		ListNode* cur = head;
//		while (!pq.empty()) {
//			Front top = pq.top();
//			pq.pop();
//			cur->next = top.ptr;
//			cur = cur->next;
//			if (top.ptr->next)
//				pq.push({ top.ptr->next->val, top.ptr->next });
//		}
//		return head->next;
//	}
//};

