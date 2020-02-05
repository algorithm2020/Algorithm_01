#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;
	multiset<int>s;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		s.insert(a);
	}
	int sum = *s.begin();
	int start = *s.begin();
	for (auto it = s.begin(); it != s.end();) {

		it++;
		if (it == s.end()) break;
		int end = *it;
		sum += start + end;
		start = start + end;
	}
	cout << sum;
	return 0;
}