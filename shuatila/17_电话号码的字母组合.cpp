class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.length() < 1)return vector<string>();
		string lettet[8] = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
		vector<string> res;
		res.push_back("");
		for (int i = 0; i < digits.length(); i++) {
			vector<string> tmp;
			tmp.swap(res);
			string choose = lettet[digits[i] - '2'];
			for (int j = 0; j < choose.length(); j++) {
				for (int k = 0; k < tmp.size(); k++) {
					res.push_back(tmp[k] + choose[j]);
				}
			}
		}
		return res;
	}
};