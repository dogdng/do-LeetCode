class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int sum = nums[0];
		int maxx = sum;
		for (int i = 1; i < nums.size(); i++) {
			sum = max(sum + nums[i], nums[i]);
			maxx = max(maxx, sum);
		}
		return maxx;
	}
};