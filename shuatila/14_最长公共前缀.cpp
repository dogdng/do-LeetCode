class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() < 1) {
			return "";
		}
		string fl("");
		int mins = 0x7fffffff;
		int ind = 0;
		for (int i = 0; i < strs.size(); i++) {
			if (strs[i].length() < mins) {
				mins = strs[i].length();
				ind = i;
			}
		}
		for (int i = 0; i < strs[ind].length(); i++) {
			for (int j = 0; j < strs.size(); j++) {
				if (strs[ind][i] != strs[j][i]) {
					return fl;
				}
			}
			fl += strs[ind][i];
		}
		return fl;
	}
};