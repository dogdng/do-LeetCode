/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	priority_queue<int> dui;
	void search(TreeNode* root, int k) {
		if (root == NULL)return;
		if (dui.size() < k) {
			dui.push(root->val);
		}
		else if (dui.top() > root->val) {
			dui.push(root->val);
			dui.pop();
		}
		search(root->left, k);
		search(root->right, k);
	}
	int kthSmallest(TreeNode* root, int k) {
		search(root, k);
		return dui.top();
	}
};