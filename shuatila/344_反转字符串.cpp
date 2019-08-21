class Solution {
public:
	void reverseString(vector<char>& s) {
		char tmp;
		int i = s.size() - 1;
		int j = 0;
		while (i > j) {
			tmp = s[i];
			s[i--] = s[j];
			s[j++] = tmp;
		}
	}
};
/*class Solution {
public:
	void reverseString(vector<char>& s) {
		int i = s.size() - 1;
		int j = 0;
		while (i > j) {
			s[i] ^= s[j];
			s[j] ^= s[i];
			s[i--] ^= s[j++];
		}
	}
};*/