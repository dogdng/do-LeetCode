#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}
	stack<int> stc;
	stack<int> data;
	void push(int x) {
		data.push(x);
		if (stc.empty() || stc.top() > x) {
			stc.push(x);
		}
		else {
			stc.push(stc.top());
		}
	}

	void pop() {
		stc.pop();
		data.pop();
	}

	int top() {
		return data.top();
	}

	int getMin() {
		return stc.top();
	}
};


int main() {
	int x = 9;
	MinStack* obj = new MinStack();
	obj->push(-2);
	obj->push(0);
	obj->push(-3);
	int param_2 = obj->getMin();
	obj->pop();
	int param_3 = obj->top();
	int param_4 = obj->getMin();
	return 0;
}
