//ÊúÊ½³Ë·¨
class Solution {
public:
	string multiply(string num1, string num2) {
		string ans(num1.length() + num2.length(), 0);
		for (int i = num1.length() - 1; i >= 0; i--) {
			for (int j = num2.length() - 1; j >= 0; j--) {
				int temp = (num1[i] - '0')*(num2[j] - '0') + ans[i + j + 1];
				ans[i + j + 1] = temp % 10;
				ans[i + j] += temp / 10;

			}
		}
		int i = 0;
		for (; i < ans.length() - 1; i++) {
			if (ans[i] != 0) {
				break;
			}
		}
		for (int j = 0; j < ans.length(); j++) {
			ans[j] += '0';
		}
		return ans.substr(i);
	}
};