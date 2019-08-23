#include <bits/stdc++.h>
using namespace std;
//��ʱ�����������������������Ż�
	#define FFF  202
	int maxDistance(vector<vector<int>>& grid) {
		int maxx = -1;
		vector<vector<int>> help(grid.size(), vector<int>(grid.size(), FFF));
		int rad = (grid.size() + 1) / 2;
		vector<pair<int, int> > land;//½��
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid.size(); j++)
			{
				if (grid[i][j] == 1) {
					land.push_back({i,j});
				}
			}
		}
		if(land.size()<1){//ֻ�к���
			return -1;
		}
		///��ÿ��½��Ϊ���ģ���ī��ȡ��С��help[p][q] = min(minn, help[p][q]);
		for (int i = 0; i < land.size(); i++) {//ÿ���
			int x = land[i].first;
			int y = land[i].second;
			int rad = max( max((int)(grid.size() - x - 1), x), max((int)(grid.size() - y - 1), y));
			int p = x;
			int q = y;
			for (int c = 0; c <= rad; c++) {//��ɢ
				p = x - c;
				q = y - c;
				for (; p < x + c; p++) {
					if (p >= 0 && q >= 0 && p < grid.size() && q < grid.size()) {
						if (grid[p][q] == 0) {
							help[p][q] = min(help[p][q],abs(p - x) + abs(q - y));
						}
						else {
							help[p][q] = FFF;
						}
					}
				}
				for (; q < y + c; q++) {
					if (p >= 0 && q >= 0 && p < grid.size() && q < grid.size()) {
						if (grid[p][q] == 0) {
							help[p][q] = min(help[p][q], abs(p - x) + abs(q - y));
						}
						else {
							help[p][q] = FFF;
						}
					}
				}
				for (; p >x-c; p--) {
					if (p >= 0 && q >= 0 && p < grid.size() && q < grid.size()) {
						if (grid[p][q] == 0) {
							help[p][q] = min(help[p][q], abs(p - x) + abs(q - y));
						}
						else {
							help[p][q] = FFF;
						}
					}
				}
				for (; q > y - c; q--) {
					if (p >= 0 && q >= 0 && p < grid.size() && q < grid.size()) {
						if (grid[p][q] == 0) {
							help[p][q] = min(help[p][q], abs(p - x) + abs(q - y));
						}
						else {
							help[p][q] = FFF;
						}
					}
				}
			}
		}
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid.size(); j++)
			{
				if (help[i][j] != FFF) {
					maxx = max(maxx, help[i][j]);
				}
			}
		}
		return maxx;
	}

int main() {
	vector<vector<int>> grid(3, vector<int>(3));
	grid[0][0] = 1;
	grid[0][1] = 0;
	grid[0][2] = 1;
	grid[1][0] = 0;
	grid[1][1] = 0;
	grid[1][2] = 0;
	grid[2][0] = 1;
	grid[2][1] = 0;
	grid[2][2] = 1;
	cout << maxDistance(grid) << endl;

	return 0;
}