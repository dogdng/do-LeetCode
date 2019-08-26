#include <bits/stdc++.h>
using namespace std;
static bool cmp(const int &a, const int &b) {
	return a > b;
}
struct tt{
	int a;		//4  4
	char ch;	//1  8
	char ch2;   //1  8
	float fl;	//4  12
	double d;	//8  24
	int *pi;	//4  32
	int *p2;    //   32
	int *p3;    //   32
	int *p4;    //   32
	int *p5;	//   48
	char *p;	//4  48
	int mat[4];	//16 64
}str;
struct bbbb{
	int a;
	int aa;
	int aaa;
};
int main() {
	cout << sizeof(str) << endl;
	//cout << sizeof(str.a) << endl;
	//cout << sizeof(str.ch) << endl;
	//cout << sizeof(str.fl) << endl;
	cout << sizeof(str.d) << endl;
	//cout << sizeof(str.pi) << endl;
	//cout << sizeof(str.p) << endl;
	//cout << sizeof(str.mat) << endl;
	tt fb;
	//cout << sizeof(fb) << endl;
	//cout << sizeof(bbbb) << endl;
	return 0;
}