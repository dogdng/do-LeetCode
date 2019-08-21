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
	ListNode* reverseList(ListNode* head) {
		stack<int> s;
		ListNode* res;
		ListNode* fu;
		res = new ListNode(0);
		fu = res;
		while (head != NULL) {
			s.push(head->val);
			head = head->next;
		}
		while (!s.empty()) {
			ListNode* tmp;
			tmp = new ListNode(s.top());
			s.pop();
			res->next = tmp;
			res = res->next;
		}
		return fu->next;
	}
};