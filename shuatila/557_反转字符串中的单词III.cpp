#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s) {
	stack<char> tmp;
	int len=s.length();
	string res;
	for (int i = 0; i < len; i++) {
		if (s[i] == ' ') {
			while (!tmp.empty()) {
				res += tmp.top();
				tmp.pop();
			}
			res += ' ';
		}
		else {
			tmp.push(s[i]);
		}
	}
	while (!tmp.empty()) {
		res += tmp.top();
		tmp.pop();
	}
	return res;
}

int main()
{
	cout << reverseWords("Let's take LeetCode contest");
	return 0;
}