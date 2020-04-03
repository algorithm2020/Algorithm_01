#include <bits/stdc++.h>
using namespace std;
string s;
int ans = 0;

int main() {
	cin >> s;

	int sz = s.size();
	stack<pair<int, bool>>st;

	for (int idx = 0; idx < sz; idx++) {
		int tmp = 0;
		if (s[idx] == '(' || s[idx] == '[') {
			st.push({ s[idx],1 });
		}
		else if (s[idx] == ']' && !st.empty() && st.top().first == '[' &&st.top().second == 1) {
			st.pop();
			st.push({ 3,0 });
		}
		else if (s[idx] == ')' && !st.empty() && st.top().first == '(' &&st.top().second == 1) {
			st.pop();
			st.push({ 2,0 });
		}
		else if (s[idx] == ')') {
			while (!st.empty() && st.top().second == 0) {
				tmp += st.top().first;
				st.pop();
			}
			if (st.empty()) {
				cout << 0;
				return 0;
			}
			else if (st.top().second == 1 && st.top().first == '(') {
				tmp *= 2;
				st.pop();
				st.push({ tmp,0 });
			}
			else {
				cout << 0;
				return 0;
			}

		}
		else if (s[idx] == ']') {
			while (!st.empty() && st.top().second == 0) {
				tmp += st.top().first;
				st.pop();
			}
			if (st.empty()) {
				cout << 0;
				exit(0);
			}
			else if (st.top().second == 1 && st.top().first == '[') {
				tmp *= 3;
				st.pop();
				st.push({ tmp,0 });
			}
			else {
				cout << 0;
				exit(0);
			}

		}
	}

	while (!st.empty()) {
		if (st.top().second == 0) {
			ans += st.top().first;
			st.pop();
		}
		else {
			cout << 0;
			exit(0);
		}
	}
	cout << ans;

	return 0;
}