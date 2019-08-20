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
	long max = -2147483649;
	bool flag = true;
	void order(TreeNode* root) {
		if (root == NULL)return;
		order(root->left);
		if (max < root->val) {
			max = root->val;
		}
		else {
			flag = false;
			return;
		}
		order(root->right);
	}
	bool isValidBST(TreeNode* root) {
		order(root);
		return flag;
	}
};