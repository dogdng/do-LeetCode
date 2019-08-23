#include <bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};


class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL)return false;
		ListNode * p1 = head;
		ListNode * p2 = head;
		while (1) {
			if (p1->next == NULL)return false;
			if (p2->next == NULL || p2->next->next == NULL)return false;
			p1 = p1->next;
			p2 = p2->next->next;
			if (p1 == p2) break;
		}
		return true;
	}
};