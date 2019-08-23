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
	int max;
	int search(TreeNode* root) {

		if (root == NULL) return 0;
		int sum = 0;
		int l = 0, r = 0;
		l = search(root->left);
		if (l > 0)sum += l;
		r = search(root->right);
		if (r > 0)sum += r;
		sum += root->val;
		if (max < sum)max = sum;
		if (l > 0 && r > 0) {
			if (l > r) {
				sum -= r;
			}
			else {
				sum -= l;
			}
		}
		return sum;
	}
	int maxPathSum(TreeNode* root) {
		max = root->val;
		search(root);
		return max;
	}
};