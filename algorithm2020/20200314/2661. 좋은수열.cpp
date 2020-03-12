#include <bits/stdc++.h>
using namespace std;
int n;
int s[80] = { 1 };
//유효한 문자열인지 체크
bool isValid(int sz) {
	if (sz <= 3)return true;
	for (int i = 2; i <= sz / 2; i++) {
		int cnt = 0;
		for (int j = i; j > 0; j--) {
			if (s[sz - j] == s[sz - i - j]) {
				cnt++;
			}
		}
		if (cnt == i) return false;
	}
	return true;
}
void recur(int num) {
	if (num == n) {
		for (int i = 0; i < n; i++) {
			cout << s[i];
		}
		exit(0);
	}

	for (int i = 1; i <= 3; i++) {
		if (s[num - 1] == i) continue;
		s[num] = i;
		if (isValid(num + 1)) recur(num + 1);
	}
}
int main() {
	cin >> n;
	recur(1);

	return 0;
}