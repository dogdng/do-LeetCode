class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int len = nums.size();
		vector<int> res;
		for (int i = 0; i < len; i++) {
			int idx = (nums[i] - 1) % len;
			nums[idx] += len;
		}
		for (int i = 0; i < len; i++) {
			if (nums[i] <= len) {
				res.push_back(i + 1);
			}
		}
		return res;
	}
};