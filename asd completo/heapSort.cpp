#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

template <typename T> vector <T> heapSort (vector<T> v) {
	
	priority_queue <T> pq;
	for (T x: v) pq.push (x);
	
	vector <T> ret;
	while (not pq.empty()) ret.push_back (pq.top()), pq.pop();
	
	reverse (ret.begin(), ret.end());
	
	return ret;
}

int main () {
	
	vector <int> v = {1, 4, 3, 5, 2};
	v = heapSort (v);
	for (int x: v) cout << x << ' ';
	
}
