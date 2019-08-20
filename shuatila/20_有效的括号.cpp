//超过100%的对手，哈哈哈哈
class Solution {
public:
	bool isValid(string s) {
		if (s.length() < 1)return true;
		stack<char> sub;
		for (int i = 0; i < s.length(); i++) {
			switch (s[i]) {
			case '(':sub.push(s[i]); break;
			case '[':sub.push(s[i]); break;
			case '{':sub.push(s[i]); break;
			case ')':
				if (!sub.empty()) {
					if (sub.top() != '(') {
						return false;
					}
					sub.pop();
				}
				else return false; break;
			case ']':
				if (!sub.empty()) {
					if (sub.top() != '[') {
						return false;
					}
					sub.pop();
				}
				else return false; break;
			case '}':
				if (!sub.empty()) {
					if (sub.top() != '{') {
						return false;
					}
					sub.pop();
				}
				else return false;
				break;
			}
		}
		if (!sub.empty())return false;
		return true;
	}
};