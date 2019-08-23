#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:
	int cap;
	list<pair<int, int>> listP;
	unordered_map<int, list<pair<int, int>>::iterator> m;

	LRUCache(int capacity) : cap(capacity) {}

	int get(int key) {
		auto it = m.find(key);
		if (it == m.end()) return -1;
		listP.splice(listP.begin(), listP, it->second);

		return it->second->second;
	}

	void put(int key, int value) {
		auto it = m.find(key);
		if (it != m.end()) listP.erase(it->second);
		listP.push_front(make_pair(key, value));
		m[key] = listP.begin();
		if (m.size() > cap) {
			int k = listP.rbegin()->first;
			listP.pop_back();
			m.erase(k);
		}
	}
};