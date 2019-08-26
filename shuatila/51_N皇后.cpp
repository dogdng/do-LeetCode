class Solution {
public:
	int N;
	int cnt = 0;
	vector<bool> col;
	vector<bool> main;
	vector<bool> mino;

	vector<vector<int> > slu;
	void pre(vector<int> &path, int row) {
		if (row == N) {
			slu.push_back(path);
			return;
		}
		for (int i = 0; i < N; i++) {
			if (canLay(row, i)) {
				path[i] = row;
				col[i] = true;
				main[N - 1 + row - i] = true;
				mino[row + i] = true;
				pre(path, row + 1);
				col[i] = false;
				main[N - 1 + row - i] = false;
				mino[row + i] = false;
			}
		}
	}
	bool canLay(int row, int co) {
		return !col[co] && !main[N - 1 + row - co] && !mino[row + co];
	}
	vector<vector<string> > solveNQueens(int n) {
		N = n;
		col.resize(n);
		main.resize(n * 2 - 1);
		mino.resize(n * 2 - 1);
		vector<int> path(n, 0);

		pre(path, 0);
		vector<vector<string> > map(slu.size(), vector<string>(n));

		for (int i = 0; i < slu.size(); i++) {
			for (int j = 0; j < slu[i].size(); j++) {
				for (int k = 0; k < N; k++) {
					if (slu[i][j] == k) {
						map[i][j] += 'Q';
					}
					else {
						map[i][j] += '.';
					}
				}
			}
		}
		return map;
	}
};