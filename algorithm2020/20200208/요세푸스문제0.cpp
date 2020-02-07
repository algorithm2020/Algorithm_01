#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	queue<int>q;
	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}
	cout << "<";
	while (n--) {
		int cnt = 0;
		while (++cnt < k) {
			int first = q.front();
			q.pop();
			q.push(first);
		}
		cout << q.front();
		if (n != 0)cout << ", ";
		q.pop();
	}
	cout << ">";
	return 0;
}