#include <bits/stdc++.h>
using namespace std;
int d[1001][1001];

int main() {
	string a;
	string b;

	int ans = 0;
	cin >> a >> b;
	a = " " + a;
	b = " " + b;

	int sz1 = a.size();
	int sz2 = b.size();
	for (int i = 1; i < sz1; i++) {
		for (int j = 1; j < sz2; j++) {
			if (a[i] == b[j]) {
				d[i][j] = d[i - 1][j - 1] + 1;
			}
			else {
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
			}
			ans = max(ans, d[i][j]);
		}
	}
	cout << ans;
	return 0;
}