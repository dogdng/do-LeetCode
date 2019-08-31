class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int min = -1;
		for (int i = nums.size() - 1; i > 0; i--) {
			if (nums[i - 1] < nums[i]) {
				min = i - 1;
				break;
			}
		}
		if (min == -1) {
			sort(nums.begin(), nums.end());
			return;
		}
		else {
			int max = nums.size() - 1;
			for (int i = min + 1; i < nums.size(); i++) {
				if (nums[i] <= nums[min]) {
					max = i - 1;
					break;
				}
			}
			int tmp = nums[min];
			nums[min] = nums[max];
			nums[max] = tmp;
			sort(nums.begin() + min + 1, nums.end());
		}
	}
};