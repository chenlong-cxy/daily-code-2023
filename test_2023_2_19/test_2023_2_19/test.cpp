//#include <iostream>
//#include <vector>
//#include <ctime>
//using namespace std;
//////数组中第k大的数字
////class Solution {
////public:
////	int findKthLargest(vector<int>& nums, int k) {
////		srand((unsigned int)time(nullptr));
////		return quickSort(nums, 0, nums.size() - 1, nums.size() - k);
////	}
////	int quickSort(vector<int>& nums, int left, int right, int pos) {
////		int keyIndex = rand() % (right - left + 1) + left; //随机生成key的下标
////		int key = nums[keyIndex];
////		swap(nums[left], nums[keyIndex]); //将key交换到最左边
////		//将小于key的元素交换到index及其之前
////		int index = left;
////		for (int i = left + 1; i <= right; i++) {
////			if (nums[i] < key) {
////				swap(nums[++index], nums[i]);
////			}
////		}
////		//将index处的元素和key交换，此时key左边的都小于key，key右边的都大于等于key
////		swap(nums[index], nums[left]);
////		if (index == pos) //key为第k大的元素
////			return nums[index];
////		else if (index > pos) //右边继续找
////			return quickSort(nums, left, index - 1, pos);
////		else //左边继续找
////			return quickSort(nums, index + 1, right, pos);
////	}
////};
//class Solution {
//public:
//	int findKthLargest(vector<int>& nums, int k) {
//		buildSmallHeap(nums, k); //用前k个数建小堆
//		for (int i = k; i < nums.size(); i++) {
//			if (nums[i] < nums[0]) //小于堆顶的元素，无需插入
//				continue;
//			swap(nums[0], nums[i]);
//			adjustDown(nums, 0, k);
//		}
//		return nums[0];
//	}
//	//建堆
//	void buildSmallHeap(vector<int>& nums, int heapSize) {
//		for (int i = (heapSize - 1 - 1) / 2; i >= 0; i--) {
//			adjustDown(nums, i, heapSize);
//		}
//	}
//	//堆的向下调整算法
//	void adjustDown(vector<int>& nums, int parent, int heapSize) {
//		int child = parent * 2 + 1; //默认左孩子是较小的
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
////自顶向下（需要递归开销）
//class Solution {
//public:
//	ListNode* sortList(ListNode* head) {
//		return sortList(head, nullptr);
//	}
//	ListNode* sortList(ListNode* head, ListNode* tail) {
//		if (head == nullptr) //链表为空
//			return head;
//		if (head->next == tail) { //链表中只有一个结点
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
//	//对两个链表进行归并排序
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
////自底向上（空间复杂度O(1)）
//class Solution {
//public:
//	ListNode* sortList(ListNode* head) {
//		if (head == nullptr)
//			return head;
//		//统计链表中的结点个数
//		int length = 0;
//		ListNode* cur = head;
//		while (cur) {
//			length++;
//			cur = cur->next;
//		}
//		ListNode* tmpHead = new ListNode;
//		tmpHead->next = head;
//		for (int sortLength = 1; sortLength < length; sortLength *= 2) { //每次合并的结点个数翻倍
//			ListNode* prev = tmpHead, *curr = tmpHead->next;
//			while (curr) {
//				//链表1
//				ListNode* head1 = curr;
//				for (int i = 1; i < sortLength&&curr->next; i++) {
//					curr = curr->next;
//				}
//				//链表2
//				ListNode* head2 = curr->next;
//				curr->next = nullptr; //链表1的尾置空
//				curr = head2; //更新curr到head2
//				for (int i = 1; i < sortLength&&curr; i++) {
//					curr = curr->next;
//				}
//				if (curr) { //需要更新curr位置
//					ListNode* nextNode = curr->next;
//					curr->next = nullptr; //链表2的尾置空
//					curr = nextNode;
//				}
//				//合并链表1和链表2
//				ListNode* merged = merge(head1, head2);
//				prev->next = merged; //将当前合并链表与之前的链表连接起来
//				while (prev->next) //找到当前合并链表的尾结点，便于与下一次合并的链表进行连接
//					prev = prev->next;
//			}
//		}
//		return tmpHead->next;
//	}
//	//合并两个有序链表
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

////合并数组中的多个有序链表
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
//		//将每个链表的第一个结点放入小堆中
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

