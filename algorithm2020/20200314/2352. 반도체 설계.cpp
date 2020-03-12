#include <bits/stdc++.h>
using namespace std;
int n;
struct Node {
	int x, y;
};
vector<Node>v;
vector<int>arr;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back({ i + 1, x });
	}

	arr.push_back(-1);
	for (int i = 0; i < n; i++) {
		if (v[i].y > arr.back()) arr.push_back(v[i].y);
		else {
			auto it = lower_bound(arr.begin(), arr.end(), v[i].y);
			*it = v[i].y;
		}
	}
	cout << arr.size() - 1;
	return 0;
}