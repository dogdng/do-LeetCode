#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ans(2, 0);
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[j] + nums[i] == target) {
					ans[0] = i;
					ans[1] = j;
					return ans;
				}
			}
		}

	}
};

int main() {
	Solution solution;
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);
	vector<int> ans = solution.twoSum(nums, 9);
	cout << ans[0] << "," << ans[1] << endl;
	return 0;
}