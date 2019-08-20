#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	string ordered(TreeNode* p)
	{
		string res;
		if (p == NULL)return res += '*';
		res += p->val;
		res += ordered(p->left);
		res += ordered(p->right);
		return res;
	}
	bool isSameTree(TreeNode* p, TreeNode* q) {
		string sp = ordered(p);
		string sq = ordered(q);
		return sp == sq;
	}
};

int main() {
	Solution slu;
	TreeNode *p;
	TreeNode *q;
	p = new TreeNode(1);
	q = new TreeNode(1);
	TreeNode *tmp;
	tmp = new TreeNode(2);
	p->left = tmp;
	TreeNode *tmp2;
	tmp2 = new TreeNode(3);
	p->right = tmp2;

	slu.isSameTree(p, q);
	
	return 0;
}