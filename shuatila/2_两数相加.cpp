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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int s1 = 0;
		int s2 = 0;
		ListNode* cur;
		ListNode* ans;
		cur = new ListNode(0);
		ans = cur;
		int ten = 0;
		while (ten || l1 != NULL || l2 != NULL) {
			if (l1 != NULL) {
				s1 = l1->val;
				l1 = l1->next;
			}
			else {
				s1 = 0;
			}
			if (l2 != NULL) {
				s2 = l2->val;
				l2 = l2->next;
			}
			else {
				s2 = 0;
			}
			int sum = s1 + s2 + ten;
			if (sum >= 10) {
				sum -= 10;
				ten = 1;
			}
			else {
				ten = 0;
			}
			ListNode* l3;
			l3 = new ListNode(sum);
			cur->next = l3;
			cur = cur->next;
		}
		return ans->next;
	}
};