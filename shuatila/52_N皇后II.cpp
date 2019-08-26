class Solution {
public:
	int N;
	int res = 0;
	int cnt = 0;
	vector<bool> col;
	vector<bool> main;
	vector<bool> mino;

	void pre(vector<int> &path, int row) {
		if (row == N) {
			res++;
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
	int totalNQueens(int n) {
		N = n;
		col.resize(n);
		main.resize(n * 2 - 1);
		mino.resize(n * 2 - 1);
		vector<int> path(n, 0);

		pre(path, 0);

		return res;
	}
};