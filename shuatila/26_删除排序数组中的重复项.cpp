class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 1) return 0;
		int p1 = 0, p2 = 0;
		while (++p2 < nums.size()) {
			if (nums[p1] < nums[p2])nums[++p1] = nums[p2];
		}
		return ++p1;
	}
};