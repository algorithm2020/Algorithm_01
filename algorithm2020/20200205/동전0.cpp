#include <iostream>
using namespace std;
int n, k;
int arr[10];
int main() {
	cin >> n >> k;
	int res = k, cnt = 0;
	for (int i = 0; i < 10; i++) cin >> arr[i];
	//제일 가까운 동전 선택
	for (int i = n - 1; i >= 0; i--) {
		//남은 돈이 더 적으면
		if (res < arr[i]) continue;
		else if (res == 0) {
			break;
		}
		else {
			while (res >= arr[i]) {
				res -= arr[i];
				cnt++;
			}
		}
	}

	cout << cnt;
	return 0;
}