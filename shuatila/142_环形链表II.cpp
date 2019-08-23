#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL)return NULL;
		ListNode *p1 = head;
		ListNode *p2 = head;
		while (1) {
			if (p1->next == NULL)return NULL;
			if (p2->next == NULL || p2->next->next == NULL)return NULL;
			p1 = p1->next;
			p2 = p2->next->next;
			if (p1 == p2) {
				p2 = head;
				break;
			}
		}
		while (1) {
			if (p1 == p2)break;
			p1 = p1->next;
			p2 = p2->next;
		}
		return p1;
	}
};