#include <bits/stdc++.h>
using namespace std;
int n;
int d[501][501];
int sum[501][501];
int arr[501];
int recur(int i, int j) {
	if (d[i][j] != 0x3f3f3f3f) return d[i][j];
	if (j == i + 2) {
		d[i][j] = min(d[i][i + 1] + arr[j], d[i + 1][j] + arr[i]);
		sum[i][j] = min(2 * d[i][i + 1] + arr[j], 2 * d[i + 1][j] + arr[i]);
		return d[i][j];
	}
	for (int k = i; k < j; k++) {
		int a = recur(i, k);
		int b = recur(k + 1, j);
		d[i][j] = min(d[i][j], a + b);
		if (k == i) sum[i][j] = min(d[i][j] + sum[k + 1][j], sum[i][j]);
		else if (k == j - 1) sum[i][j] = min(d[i][j] + sum[i][k], sum[i][j]);
		else sum[i][j] = min(sum[i][j], sum[i][k] + sum[k + 1][j] + d[i][j]);
	}
	return d[i][j];
}
void init() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (i == j) d[i][j] = sum[i][j] = arr[i];
			else if (j == i + 1) sum[i][j] = d[i][j] = arr[i] + arr[j];
			else sum[i][j] = d[i][j] = 0x3f3f3f3f;

		}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		init();
		recur(1, n);
		cout << sum[1][n] << "\n";
	}
	return 0;
}