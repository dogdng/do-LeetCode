#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int A(int a, int b) {
		int res = 1;
		for (int i = a; i > a - b; i--) res *= i;
		return res;
	}

	int numDupDigitsAtMostN(int N) {
		if (N < 11)return 0;
		int res = 0;
		string num = to_string(N);
		for (int i = 1; i < num.length(); i++){//0开头  eg: 009
			res += 9 * A(9, i - 1);
		}
		int buf[10];
		memset(buf, 0, sizeof(buf));
		for (int i = 0; i < num.length() - 1; i++) {
			int numi = num[i] - '0';
			int tmp = 0;
			for (int j = 0; j < numi; j++) {
				if (buf[j] == 0) {
					tmp++;
				}
			}
			if (i == 0) tmp--;//0开头已经算过了
			res += tmp * A(9 - i, num.length() - i - 1);
			if (buf[numi] > 0)return N - res;
			buf[numi]++;
		}
		int numn = num[num.length() - 1] - '0';//个位单独处理
		for (int i = 0; i <= numn; i++) {
			if (buf[i] == 0)res++;
		}
		return N - res;
	}
};

int main() {
	//cout << A(5, 2) << endl;
	cout << numDupDigitsAtMostN(1) << endl << 89039 << endl;
	return 0;
}