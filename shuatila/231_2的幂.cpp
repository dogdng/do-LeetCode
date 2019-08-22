class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n <= 0)return false;
		return !(n&(n - 1));
	}
};
//class Solution {
//public:
//	bool isPowerOfTwo(int n) {
//		if (n <= 0)return false;
//		int tmp = 0;
//		for (int i = 0; !tmp; i++) {
//			tmp = n & 0x01;
//			n = n >> 1;
//		}
//		return !n;
//	}
//};