#include <bits/stdc++.h>
using namespace std;
int max1, max2, max3, min1, min2, min3;
int n;
int arr[100000][3];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	max1 =min1= arr[0][0], max2=min2 = arr[0][1], max3=min3 = arr[0][2];
	for (int i = 1; i < n; i++) {
		int new_max1 = arr[i][0] + max(max1, max2);
		int new_max2 = arr[i][1] + max(max(max1, max2), max3);
		int new_max3 = arr[i][2] + max(max2, max3);
		int new_min1 = arr[i][0] + min(min1, min2);
		int new_min2 = arr[i][1] + min(min(min1, min2), min3);
		int new_min3 = arr[i][2] + min(min2, min3);
		max1 = new_max1, max2 = new_max2, max3 = new_max3;
		min1 = new_min1, min2 = new_min2, min3 = new_min3;

	}
	cout << max(max(max1, max2), max3) << " " << min(min(min1, min2), min3);
	return 0;
}