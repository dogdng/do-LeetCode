class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 1)return 0;
		int minn = INT_MAX;
		int sum = 0;
		for (int i = 0; i < prices.size(); i++) {
			minn = min(minn, prices[i]);
			sum = max(sum, prices[i] - minn);
		}
		return sum;
	}
};