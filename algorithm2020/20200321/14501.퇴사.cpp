#include <bits/stdc++.h>
using namespace std;
int d[16];//i��°���� ó�� ����� ���������� ���� �� �ִ� ����
int T[21]; //����Ⱓ
int P[21]; //����
int ans = 0;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> T[i] >> P[i];
	}
	for (int i = n; i > 0; i--) {
		if (T[i] + i - 1 <= n) {
			d[i] = P[i];
			for (int j = T[i] + i; j <= n; j++) {
				d[i] = max(d[i], P[i] + d[j]);
			}
		}
		ans = max(ans, d[i]);
	}

	cout << ans;
	return 0;
}