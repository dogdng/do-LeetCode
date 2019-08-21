/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* mergeList(ListNode* l1, ListNode* l2) {
		ListNode* ln;
		ListNode* res;
		ln = new ListNode(0);
		res = ln;
		while (l1 != NULL && l2 != NULL) {
			if (l1->val > l2->val) {
				ln->next = l2;
				l2 = l2->next;
				ln = ln->next;
			}
			else {
				ln->next = l1;
				l1 = l1->next;
				ln = ln->next;
			}
		}
		if (l1 != NULL) ln->next = l1;
		if (l2 != NULL) ln->next = l2;
		return res->next;
	}
	ListNode* merge(vector<ListNode*>& lists, int l, int r) {
		if (l == r)return lists[l];
		int mid = (r + l) >> 1;
		return mergeList(merge(lists, l, mid), merge(lists, mid + 1, r));
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty())return NULL;
		return merge(lists, 0, lists.size() - 1);
	}
};