#include <bits/stdc++.h>
using namespace std;
int d[5000][5000];
int arr[5000];
int n;
int recur(int start, int end, bool back) {
	if (d[start][end] != -1)return d[start][end];
	else d[start][end] = 0;
	if (start > end) return 0;
	int res = 0;
	if (end - start == 1) {
		int first = arr[start];
		int second = arr[end];
		if (first > 0 && second > 0 && first < 10 && second < 10 && back) res++;
		if (first * 10 + second >= 10 && first * 10 + second <= 26) res++;
		return d[start][end] = res % 1000000;
	}

	res = d[start][start] * recur(start + 1, end, true);
	res = (res + recur(start, start + 1, false)*recur(start + 2, end, true)) % 1000000;
	return d[start][end] = res;
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j && arr[i] != 0)d[i][j] = 1;
			else if (i == j && arr[i] == 0)d[i][j] = 0;
			else d[i][j] = -1;
		}
	}
}
int main() {
	string s;
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++)arr[i] = s[i] - 48;
	init();
	cout << recur(0, n - 1, true);

	return 0;
}