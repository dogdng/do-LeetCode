#include<bits/stdc++.h>
using namespace std;

#define X 5
#define Y 5

int chess[X][Y];

int nextxy(int &x, int &y, int count) {
	switch (count) {
	case 0:
		if (x + 2 <= X - 1 && y - 1 >= 0 && chess[x + 2][y - 1] == 0) {
			x += 2;
			y -= 1;
			return 1;
		}break;
	case 1:
		if (x + 2 < X&&y + 1 < Y&&chess[x + 2][y + 1] == 0) {
			x += 2;
			y += 1;
			return 1;
		}break;
	case 2:
		if (x - 2 >= 0 && y - 1 >= 0 && chess[x - 2][y - 1] == 0) {
			x -= 2;
			y -= 1;
			return 1;
		}break;
	case 3:
		if (x - 2 >= 0 && y + 1 < Y&&chess[x - 2][y + 1] == 0) {
			x -= 2;
			y += 1;
			return 1;
		}break;
	case 4:
		if (x - 1 >= 0 && y + 2 < X&&chess[x - 1][y + 2] == 0) {
			x -= 1;
			y += 2;
			return 1;
		}break;
	case 5:
		if (x - 1 >= 0 && y - 2 >= 0 && chess[x - 1][y - 2] == 0) {
			x -= 1;
			y -= 2;
			return 1;
		}break;
	case 6:
		if (x + 1 < X&&y + 2 < Y&&chess[x + 1][y + 2] == 0) {
			x += 1;
			y += 2;
			return 1;
		}break;
	case 7:
		if (x + 1 < X&&y - 2 >= 0 && chess[x + 1][y - 2] == 0) {
			x += 1;
			y -= 2;
			return 1;
		}break;
	default:
		break;
	}
	return 0;
}

int travelChessBoard(int x, int y, int tag) {
	if (tag == X * Y) {
		cout << "success !!" << endl;
		for (int i = 0; i < X; i++) {
			for (int j = 0; j < Y; j++)
			{
				cout << chess[i][j] << "  ";
			}
			cout << endl;
		}
		return 1;
	}
	chess[x][y] = tag;
	int x1 = x;
	int y1 = y;
	int count=0;
	
	int flag = nextxy(x1,y1,count);
	while (!flag&&count < 7) {
		count++;
		flag = nextxy(x1, y1, count);
	}
	
	while (flag) {
		if (travelChessBoard(x1, y1, tag + 1)) {
			return 1;
		}
		x1 = x;
		y1 = y;
		count++;
		flag = nextxy(x1, y1, count);
		while (!flag&&count < 7) {
			count++;
			flag = nextxy(x1, y1, count);
		}
	}
	chess[x][y] = 0;
	return 0;
}


int main() {
	memset(chess, 0, sizeof(chess));
	if (!travelChessBoard(2, 0, 1)) {
		cout << "error" << endl;
	}
	return 0;
}