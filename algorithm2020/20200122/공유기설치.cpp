#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n, c;
int max_dist = 0;
int main() {
	cin >> n >> c;

	int *arr = new int[n];
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int start = 1, end = arr[n - 1] - arr[0];
	int k; //간격

	while (start <= end) {
		int cnt = 0;
		k = (start + end) / 2;

		int i = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++) {
				if (arr[i] + k <= arr[j]) {
					cnt++;
					i = j - 1;
					break;
				}
			}
		}

		//설치할 수 있으면 늘려봐야지
		if (cnt >= c - 1) {
			max_dist = max(max_dist, k);
			start = k + 1;
		}

		else {
			end = k - 1;
		}
	}

	cout << max_dist;
	delete[] arr;
	return 0;
}