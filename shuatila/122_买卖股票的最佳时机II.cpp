class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 1)return 0;
		int tmp = 0;
		bool buy = 0;
		int sum = 0;
		for (int i = 0; i < prices.size() - 1; i++) {
			if (buy == 0 && prices[i] < prices[i + 1]) {
				buy = 1;
				tmp = prices[i];
			}
			if (buy == 1 && tmp <= prices[i] && prices[i] >= prices[i + 1]) {
				sum += prices[i] - tmp;
				buy = 0;
			}
		}
		if (buy == 1)sum += prices[prices.size() - 1] - tmp;
		return sum;
	}
};