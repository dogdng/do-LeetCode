class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> res(1, 0);
		for (int i = 0; i < n; i++) {
			vector<int> tmp;
			tmp.swap(res);
			for (int j = 0; j < tmp.size(); j++) {
				if (j % 2 == 0) {
					res.push_back(tmp[j] << 1);
					res.push_back((tmp[j] << 1) + 1);
				}
				else {
					res.push_back((tmp[j] << 1) + 1);
					res.push_back(tmp[j] << 1);
				}
			}
		}
		return res;
	}
};