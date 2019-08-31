class Solution {
public:
	int hammingDistance(int x, int y) {
		int tmp = x ^ y;
		int res = 0;
		for (int i = 0; i < 32; i++) {
			res += tmp & 1;
			tmp = tmp >> 1;
		}
		return res;
	}
};