#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int> > ans;
		if (nums.size() < 3) {
			return vector<vector<int>>();
		}
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size()-1; i++) {
			if (nums[i] > 0) {
				break;
			}
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			int l = i+1;
			int r = nums.size()-1;
			while (l < r) {
				int sum = nums[i] + nums[l] + nums[r];
				if (sum == 0) {
					ans.push_back({ nums[i] , nums[l] , nums[r] });
					while (l < r&&nums[l++] == nums[l]);
					while (l < r&&nums[r--] == nums[r]);
				}
				else if(sum<0){
					l++;
				}
				else {
					r--;
				}
			}
		}
		return ans;
	}
};

int main() {
	Solution sol;
	vector<int> nums({ 0, 0, 0, 0, 0});//-1,0,0,1 });//  -4,-1,-1,0,1,2 });//-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6 });//3,0,-2,-1,1,2 });//-2,0,1,1,2 });//
	vector<vector<int> > ans;
	ans = sol.threeSum(nums);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}