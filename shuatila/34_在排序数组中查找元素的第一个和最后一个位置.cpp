#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
	
	int div(vector<int>& nums, int target, int left, int right,bool choose) {
		while (left < right) {
			int mid= left + ((right - left) >> 1);
			if (nums[mid] > target || (choose&&nums[mid] == target)) {
				right = mid;
			}
			else {
				left = mid+1;
			}
		}
		return left;
	}

	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ans(2, -1);
		if (nums.size() < 1) {
			return ans;
		}
		int tmp=div(nums, target, 0, nums.size(),true);
		if (tmp == nums.size() || nums[tmp] != target) {
			return ans;
		}
		ans[0] = tmp;
		ans[1]= div(nums, target, 0, nums.size(), false)-1;
		
		return ans;
	}
};

int main() {
	Solution slu;
	vector<int> nums;
	nums.push_back(1);
	//nums.push_back(7);
	//nums.push_back(7);
	//nums.push_back(8);
	//nums.push_back(8);
	//nums.push_back(10);
	//nums.push_back(11);
	vector<int> ans;
	ans=slu.searchRange(nums, 1);
	cout << ans[0] << "   " << ans[1] << endl;
	return 0;
}