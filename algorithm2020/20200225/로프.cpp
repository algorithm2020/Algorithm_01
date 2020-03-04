#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100000];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum = std::max((n - i)*arr[i], sum); //제일 작은 단위 * 개수
	}
	cout << sum;
	return 0;
}