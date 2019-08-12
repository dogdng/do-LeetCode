//给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
//
//注意：答案中不可以包含重复的三元组。
//
//例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
//
//满足要求的三元组集合为：
//[
//	[-1, 0, 1],
//	[-1, -1, 2]
//]
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/3sum
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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

int main1() {
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