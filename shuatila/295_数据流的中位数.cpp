#include <bits/stdc++.h>
using namespace std;
//大顶堆存小的数，小顶堆存大的数
class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}
	priority_queue<int> bigHead;
	priority_queue<int, vector<int>, greater<int> > smallHead;
	void addNum(int num) {
		bigHead.push(num);
		smallHead.push(bigHead.top());
		bigHead.pop();

		if (smallHead.size() > bigHead.size()) {
			bigHead.push(smallHead.top());
			smallHead.pop();
		}
	}
	double findMedian() {
		return bigHead.size() > smallHead.size() ? bigHead.top() : (double)(bigHead.top() + smallHead.top()) / 2;
	}
};

int main() {
	MedianFinder* obj = new MedianFinder();
	obj->addNum(2);
	obj->addNum(3);
	obj->addNum(1);
	double param_2 = obj->findMedian();
	cout << param_2 << endl;
	return 0;
}