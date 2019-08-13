//马拉车
//中间向两边遍历，如果遍历的字符在已知的回文串之间，则找对称的
class Solution {
public:
	string longestPalindrome(string s) {
		string ss(s.length() * 2 + 2, '#');
		vector<int> rad(ss.length(), 1);//存半径的数组
		ss[0] = '@';
		for (int i = 1; i <= s.length(); i++) {
			ss[i * 2] = s[i - 1];//@#s#s#s#s#s#
		}
		int r = 0;//当前最大回文区间的右边界
		int mp = 0;//最大半径的位置
		int max = 0;//当前的最大半径值
		int maxp = 0;//最大半径值
		for (int j = 1; j < ss.length(); j++) {
			if (j < r) {
				rad[j] = min(rad[2 * mp - j],//右边界之内 
					r - j);//右边界之外的，截断。
			}
			while (ss[j + rad[j]] == ss[j - rad[j]]) {
				rad[j]++;//中间向两边找回文
			}
			if (r < rad[j] + j) {//更新右边界
				r = rad[j] + j;
				mp = j;
			}
			if (max < rad[mp]) {//更新最大半径
				max = rad[mp];
				maxp = mp;
			}
		}
		return s.substr((maxp - max) / 2, max - 1);
	}
};