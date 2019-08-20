#include <bits/stdc++.h>
using namespace std;
//抠边界，毫无意义
class Solution {
public:
	int myAtoi(string str) {
		long res = 0;
		int flag = 1;
		int fir = 0;
		int len = 0;
		int num = 0;
		for (int i = 0; i < str.length(); i++) {
			if (num > 0) {
				if (!(str[i] >= '0'&&str[i] <= '9')) {
					break;
				}
			}
			if (i < str.length() - 1) {
				if (str[i] == '-') {
					if (str[i + 1] >= '0'&&str[i + 1] <= '9') {
						flag = -1;
					}
					else {
						return 0;
					}
				}
				if (str[i] == '+'&&str[i + 1] >= '0'&&str[i + 1] <= '9') {
					continue;
				}
			}
			if (fir == 0) {
				if (str[i] != ' ') {
					fir = 1;
					if (!(str[i] >= '0'&&str[i] <= '9') && str[i] != '-') {
						return 0;
					}
				}
			}
			if (str[i] == '.') {
				break;
			}
			if (str[i] >= '0'&&str[i] <= '9') {
				num = 1;
				res *= 10;
				res += str[i] - '0';
				if (res > 0)
					len++;
			}
			if (num > 0) {
				if (!(str[i] >= '0'&&str[i] <= '9')) {
					break;
				}
				if (len > 10) {
					break;
				}
			}

		}
		if (flag == -1 && res > 2147483647) {
			return INT_MIN;
		}
		if (res > 2147483647) {
			return 2147483647;
		}
		return res * flag;
	}
};
int main() {
	Solution slu;
	cout << slu.myAtoi("    +0a32");
	return 0;
}