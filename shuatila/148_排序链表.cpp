#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		vector<int> tmp;
		ListNode* res;
		res = head;
		while (head != NULL) {
			tmp.push_back(head->val);
			head = head->next;
		}
		sort(tmp.begin(), tmp.end());
		head = res;
		for (int i = 0; i < tmp.size(); i++)
		{
			head->val = tmp[i];
			head = head->next;
		}
		return res;
	}
};