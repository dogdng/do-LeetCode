#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int ans = 0;
		int diff = 0x7fffffff;
		if (nums.size() <= 3) {
			for (int i = 0; i < nums.size(); i++) {
				ans += nums[i];
			}
			return ans;
		}
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++)
		{
			int l = i + 1;
			int r = nums.size() - 1;
			while (l < r) {
				int sum = nums[i] + nums[l] + nums[r];
				if (sum > target) {
					r--;
					if (diff > abs(sum - target)) {
						ans = sum;
						diff = abs(ans - target);
					}
				}
				else if (sum < target) {
					l++;
					if (diff > abs(sum - target)) {
						ans = sum;
						diff = abs(ans - target);
					}
				}
				else {
					return sum;
				}
			}
		}
		return ans;
	}
};

int main() {
	Solution sol;
	vector<int> nums({ -1,2,1,-4 });//-1,0,0,1 });//  -4,-1,-1,0,1,2 });//-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6 });//3,0,-2,-1,1,2 });//-2,0,1,1,2 });//
	int ans;
	ans = sol.threeSumClosest(nums,1);
	//for (int i = 0; i < ans.size(); i++) {
	//	for (int j = 0; j < ans[i].size(); j++) {
	cout << ans;//[i][j] << ",";
		//}
		//cout << endl;
	//}
	return 0;
}