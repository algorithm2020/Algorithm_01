#include <iostream>
#include <algorithm>
using namespace std;
int n, m;

long long getTree(int arr[], int h) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] - h > 0) sum += arr[i] - h;
	}

	return sum;
}
int main() {
	cin >> n >> m;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int start = 0, end = arr[n - 1];
	int h = (start + end) / 2;
	while (start <= end) {
		long long tree = getTree(arr, h);
		//자른 나무가 더 많을 때에는
		if (tree > m) {
			start = h + 1;
			h = (start + end) / 2;
		}
		//자른 나무가 더 적을 때
		else if (tree < m) {
			end = h - 1;
			h = (start + end) / 2;
		}
		//자른 나무가 원하는 나무 길이와 같을 때
		else {
			cout << h;
			delete[] arr;
			return 0;
		}
	}

	cout << h;
	delete[] arr;
	return 0;
}