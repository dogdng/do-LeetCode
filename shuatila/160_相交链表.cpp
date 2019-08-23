#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL)return NULL;
		int lenA = 0;
		int lenB = 0;
		ListNode *a;
		ListNode *b;
		a = headA;
		b = headB;
		while (a->next != NULL) {
			a = a->next;
			lenA++;
		}
		while (b->next != NULL) {
			b = b->next;
			lenB++;
		}
		a = headA;
		b = headB;
		if (lenA > lenB) {
			int i = lenA - lenB;
			while (i--) {
				a = a->next;
			}
		}
		else {
			int i = lenB - lenA;
			while (i--) {
				b = b->next;
			}
		}
		while (a != NULL) {
			if (a == b) {
				return a;
			}
			a = a->next;
			b = b->next;
		}
		return NULL;
	}
};