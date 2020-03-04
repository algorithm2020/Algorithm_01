#include <bits/stdc++.h>
using namespace std;
int d[3][1001][32]; //d[i][t][w] : i번째 나무, t번째시간, 남은 횟수가 w
int arr[1001];
int ans = 0;
int t, w;
int main() {
	cin >> t >> w;
	for (int i = 1; i <= t; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= t; i++) {
		for (int j = 1; j <= w + 1; j++) {
			if (arr[i] == 1) {
				d[1][i][j] = max(d[1][i - 1][j] + 1, d[2][i - 1][j - 1] + 1);
				d[2][i][j] = max(d[1][i - 1][j - 1], d[2][i - 1][j]);
			}

			else {
				if (i == 1 && j == 1) continue;
				d[1][i][j] = max(d[1][i - 1][j], d[2][i - 1][j - 1]);
				d[2][i][j] = max(d[1][i - 1][j - 1] + 1, d[2][i - 1][j] + 1);
			}
		}
	}

	for (int i = 1; i <= w + 1; i++) {
		ans = max(ans, max(d[1][t][i], d[2][t][i]));
	}
	cout << ans;
	return 0;
}