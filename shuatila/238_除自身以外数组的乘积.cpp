class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> l(nums.size(), 1);
		vector<int> r(nums.size(), 1);
		for (int i = 1; i < nums.size(); i++) {
			l[i] = nums[i - 1] * l[i - 1];
		}
		for (int i = nums.size() - 1; i > 0; i--) {
			r[i - 1] = nums[i] * r[i];
		}
		for (int i = 0; i < nums.size(); i++) {
			l[i] = l[i] * r[i];
		}
		return l;
	}
};