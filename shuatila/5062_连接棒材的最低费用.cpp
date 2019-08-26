class Solution {
public:
	int connectSticks(vector<int>& sticks) {
		if (sticks.size() < 2)return 0;
		priority_queue<int, vector<int>, greater<int> > small;
		for (int i = 0; i < sticks.size(); i++) {
			small.push(sticks[i]);
		}
		long long sum = 0;
		for (int i = 1; i < sticks.size(); i++) {
			int tmp = small.top();
			small.pop();
			tmp += small.top();
			small.pop();
			sum += tmp;
			small.push(tmp);
		}
		return sum;
	}
};