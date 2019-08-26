class Solution {
public:
	int calculateTime(string keyboard, string word) {
		map<char, int> map;
		int sum = 0;
		for (int i = 0; i < keyboard.length(); i++) {
			map.insert(make_pair(keyboard[i], i));
		}
		sum += map[word[0]];
		for (int i = 1; i < word.length(); i++) {
			sum += abs(map[word[i]] - map[word[i - 1]]);
		}
		return sum;
	}
};