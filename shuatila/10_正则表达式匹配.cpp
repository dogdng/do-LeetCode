class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty()) return s.empty();
		bool match = false;
		if (!s.empty()) {
			if (p[0] == s[0] || p[0] == '.') {
				match = true;
			}
		}
		if (p.length() > 1 && p[1] == '*') {
			return match && isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
		}
		return match && isMatch(s.substr(1), p.substr(1));
	}
};