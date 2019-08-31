class Solution {
public:
	vector<string> ans;
	void pre(string str, int left, int right, int max) {
		if (right == max) {
			ans.push_back(str);
			return;
		}
		if (left < max)pre(str + '(', left + 1, right, max);
		if (right < left)pre(str + ')', left, right + 1, max);
	}
	vector<string> generateParenthesis(int n) {
		pre("", 0, 0, n);
		return ans;
	}
};