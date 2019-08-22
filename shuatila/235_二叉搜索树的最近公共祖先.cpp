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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		int mi = min(p->val, q->val);
		int ma = max(p->val, q->val);
		for (;;) {
			if (root->val <= ma && root->val >= mi) {
				return root;
			}
			else if (root->val > ma) {
				root = root->left;
			}
			else {
				root = root->right;
			}
		}
	}
};