#include <bits/stdc++.h>
using namespace std;
//大顶堆存小的数，小顶堆存大的数
class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}
	struct cmp {
		bool operator ()(int &a, int &b) {
			return a > b;//最小值优先 
		}
	};
	priority_queue<int> bigHead;
	priority_queue<int, vector<int>, cmp> smallHead;
	void addNum(int num) {
		cnt++;
		if (bigHead.empty()) {
			bigHead.push(num);
		}
		else {
			if (num > bigHead.top()) {
				smallHead.push(num);
				if (smallHead.size() - bigHead.size() > 1)
				{
					bigHead.push(smallHead.top());
					smallHead.pop();
				}
			}
			else {
				bigHead.push(num);
				if (bigHead.size() - smallHead.size() > 1)
				{
					smallHead.push(bigHead.top());
					bigHead.pop();
				}
			}
		}
	}
	int cnt = 0;
	double findMedian() {
		if (cnt % 2 == 0) {
			return (double)(bigHead.top() + smallHead.top()) / 2.0;
		}
		else {
			if (bigHead.size() > smallHead.size()) {
				return (double)bigHead.top();
			}
			else {
				return (double)smallHead.top();
			}
		}
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