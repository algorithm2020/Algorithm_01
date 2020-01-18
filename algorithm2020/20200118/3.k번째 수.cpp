#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[5000000];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n;i++) {
		int num;
		cin >> num;
		arr[i] = num;
	}

	sort(arr, arr+n,less<int>());
	cout << arr[k-1];
	return 0;
}
