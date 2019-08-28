class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() < 1)return 0;
		int res = nums[0];
		int pre = 0;
		for (int i = 1; i < nums.size(); i++) {
			int tmp = res;
			res = max(nums[i] + pre, res);
			pre = tmp;
		}
		return res;
	}
};