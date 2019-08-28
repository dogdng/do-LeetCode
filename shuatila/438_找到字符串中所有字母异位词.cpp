class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		if (s.length() < p.length())return vector<int>();
		vector<int> res;
		vector<int> buf(127, 0);
		for (int i = 0; i < p.length(); i++) {
			buf[p[i]]++;
		}
		for (int i = 0; i < 127; i++) {
			if (buf[i] == 0) buf[i]--;
		}
		vector<int> tmp;
		tmp = buf;
		for (int p1 = 0, p2 = 0; p2 < s.length(); p2++) {
			if (tmp[s[p2]] >= 0) {
				tmp[s[p2]]--;
				while (tmp[s[p2]] < 0) {
					tmp[s[p1]]++;
					p1++;
				}
				if (p2 - p1 == p.length() - 1) {
					res.push_back(p1);
					tmp[s[p1]]++;
					p1++;
				}
			}
			else {
				tmp = buf;
				p1 = p2;
				p1++;
			}
		}
		return res;
	}
};