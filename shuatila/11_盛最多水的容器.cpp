//双指针，短的向长的移动
class Solution {
public:
	int maxArea(vector<int>& height) {
		int i = 0, j = height.size() - 1;
		int v = 0;
		while (i != j) {
			v = max(v, (j - i)*(height[i] > height[j] ? height[j--] : height[i++]));
		}
		return v;
	}
};