#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.size() < 1) {
			return vector<int>();
		}
		vector<int> res;
		int d = matrix.size()-1;
		int r = matrix[0].size()-1;
		int u = 0;
		int l = 0;
		while (1) {
			for (int i = l; i <= r; i++) {
				res.push_back(matrix[u][i]);
			}
			u++;
			if (u > d)break;
			for (int i = u; i <= d; i++) {
				res.push_back(matrix[i][r]);
			}
			r--;
			if (r < l)break;
			for (int i = r; i >= l; i--) {
				res.push_back(matrix[d][i]);
			}
			d--;
			if (d < u)break;
			for (int i = d; i >= u; i--) {
				res.push_back(matrix[i][l]);
			}
			l++;
			if (l > r)break;
		}
		return res;
	}
};

int main() {
	Solution slu;
	vector<vector<int>> matrix(3);
	matrix[0].push_back(1);
	//matrix[0].push_back(2);
	//matrix[0].push_back(3);
	//matrix[0].push_back(4);
	matrix[1].push_back(5);
	//matrix[1].push_back(6);
	//matrix[1].push_back(7);
	//matrix[1].push_back(8);
	matrix[2].push_back(9);
	//matrix[2].push_back(10);
	//matrix[2].push_back(11);
	//matrix[2].push_back(12);
	vector<int> res = slu.spiralOrder(matrix);
	return 0;
}
