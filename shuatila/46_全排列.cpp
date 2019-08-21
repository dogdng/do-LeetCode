#include <bits/stdc++.h>
using namespace std;
//交换！！不好理解
class Solution {
public:
	void swap(int &a, int &b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	vector<vector<int>> res;
	void back(vector<int>& nums, int idx) {
		if (idx == nums.size())res.push_back(nums);
		for (int i = idx; i < nums.size(); i++) {
			swap(nums[i], nums[idx]);
			back(nums, idx + 1);
			swap(nums[i], nums[idx]);
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		back(nums, 0);
		return res;
	}
};

int main() {
	Solution slu;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	vector<vector<int>> res=slu.permute(nums);
	
	return 0;
}