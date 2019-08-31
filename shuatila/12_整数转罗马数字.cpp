class Solution {
public:
	string intToRoman(int num) {
		string inte[13] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };
		int value[13] = { 1 ,  4 , 5 ,  9 , 10, 40 , 50 , 90,100, 400,500, 900,1000 };
		string res;
		int i = 12;
		while (num / value[i] == 0)i--;
		while (i >= 0) {
			num -= value[i];
			res += inte[i];
			while (i >= 0 && num / value[i] == 0)i--;
		}
		return res;
	}
};