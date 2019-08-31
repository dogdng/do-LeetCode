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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* res = new ListNode(0);
		ListNode* head2;
		res->next = head;
		head2 = head;
		head = res;
		while (n--) {
			head2 = head2->next;
		}
		while (head2 != NULL) {
			res = res->next;
			head2 = head2->next;
		}
		res->next = res->next->next;
		res = head;
		return res->next;
	}
};
/*
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* res = new ListNode(0);
		res->next = head;
		int len = 0;
		while (head != NULL) {
			len++;
			head = head->next;
		}
		len -= n;
		head = res;
		while (len > 0) {
			res = res->next;
			len--;
		}
		res->next = res->next->next;
		res = head;
		return res->next;
	}
};
*/