class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n));
		int d = n - 1;
		int r = n - 1;
		int l = 0;
		int u = 0;
		int num = 1;
		while (1) {
			for (int i = l; i <= r; i++) {
				res[u][i] = num++;
			}
			u++;
			if (u > d)break;
			for (int i = u; i <= d; i++) {
				res[i][r] = num++;
			}
			r--;
			if (l > r)break;
			for (int i = r; i >= l; i--) {
				res[d][i] = num++;
			}
			d--;
			if (u > d)break;
			for (int i = d; i >= u; i--) {
				res[i][l] = num++;
			}
			l++;
			if (l > r)break;
		}
		return res;
	}
};