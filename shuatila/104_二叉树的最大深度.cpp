struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		int dep = 0;
		if (root == NULL) {
			return dep;
		}
		dep++;
		dep += max(maxDepth(root->left), maxDepth(root->right));
		return dep;
	}
};