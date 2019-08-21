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
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL)return 0;
		ListNode* res;
		ListNode* tem;
		int len = 1;
		tem = head;
		while (head->next != NULL) {
			head = head->next;
			len++;
		}
		int move = len - (k%len);
		head->next = tem;//变成环
		for (int i = 0; i < move - 1; i++) {
			tem = tem->next;
		}
		res = tem->next;//打开环
		tem->next = NULL;
		return res;
	}
};