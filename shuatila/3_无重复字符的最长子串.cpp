class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int pos[256];
		memset(pos, 0, sizeof(pos));
		int l = 0;
		int ans = 0;
		for (int i = 0; i < s.length(); i++) {
			if (pos[s[i]] == 0 || pos[s[i]] < l) {
				ans = max(ans, i - l + 1);
			}
			else {
				l = pos[s[i]];
			}
			pos[s[i]] = i + 1;
		}
		return ans;
	}
};