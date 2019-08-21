//自我复制两份，一份加上修改后的另一份。
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		res.push_back(vector<int>());
		for (int i = 0; i < nums.size(); i++) {
			vector<vector<int>> tmp(res);
			int j = res.size();
			while (j--) {
				tmp[j].push_back(nums[i]);
				res.push_back(tmp[j]);
			}
		}
		return res;
	}
};


/*
//递归回溯
class Solution {
public:
	vector<vector<int>> res;
	void sub(vector<int>& nums,vector<int> &help,int index){
		if(index<nums.size()){
			help.push_back(nums[index]);
			res.push_back(help);
			sub(nums,help,index+1);
			help.pop_back();
			sub(nums,help,index+1);
		}
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> help;
		res.push_back(help);
		sub(nums,help,0);
		return res;
	}
};*/