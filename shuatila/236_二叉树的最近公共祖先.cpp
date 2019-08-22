//leetcode的返回值如果不是在最后一行，即使执行通过，提交也会出现错误！可以使用goto将需要返回的值放到最后
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
		stack<TreeNode*> stc;
		stc.push(root);
		int last;
		int flag = 0;
		int cnt = 0;
		while (!stc.empty()) {
			TreeNode* tmp;
			tmp = stc.top();
			if (flag == 0) {
				if (tmp->val == p->val) {
					last = q->val;
					flag = 1;
				}
				if (tmp->val == q->val) {
					last = p->val;
					flag = 1;
				}
				cnt = 0;
			}
			else if (tmp->val == last) {
				goto fu;
			}
			if (tmp->left != NULL) {
				stc.push(tmp->left);
				if (flag)cnt++;
				tmp->left = NULL;
			}
			else if (tmp->right != NULL) {
				stc.push(tmp->right);
				if (flag)cnt++;
				tmp->right = NULL;
			}
			else {
				stc.pop();
				if (cnt > 0) {
					if (flag) cnt--;
				}
			}
		}
	fu:
		while (cnt--) stc.pop();
		return stc.top();
	}
};