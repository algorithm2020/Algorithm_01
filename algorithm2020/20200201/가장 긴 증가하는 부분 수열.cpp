#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int d[1001], a[1001] = { 0 }; //d[i] :A[i]로 끝나는 가장 긴 증가하는 부분 수열의 길이

int main() {
	int n;
	cin >> n;
	int len = 1;
	for (int i = 1; i <= n; i++) {
		int s;
		scanf("%d", &s);
		a[i] = s;
	}

	d[1] = 1;


	for (int i = 2; i <= n; i++) {
		d[i] = 1;

		for (int j = 1; j < i; j++) {
			if (a[j] < a[i]) {
				d[i] = std::max(d[j] + 1, d[i]);
			}
		}
		len = max(len, d[i]);

	}


	printf("%d", len);
	return 0;
}