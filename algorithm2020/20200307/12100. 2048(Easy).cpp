#include <bits/stdc++.h>
using namespace std;
int n = 4;
int ans = 0;
int arr_move(int mode, int arr[][20]) {
	int arr_copy[20][20];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr_copy[i][j] = arr[i][j];
		}
	}
	//상
	if (mode == 0) {
		for (int j = 0; j < n; j++) {
			//합치기
			for (int i = 0; i < n - 1; i++) {
				if (arr[i][j] != 0)
					for (int k = i + 1; k < n; k++) {
						if (arr[i][j] != arr[k][j] && arr[k][j] == 0) continue;
						else if (arr[i][j] != arr[k][j] && arr[k][j] != 0) break;
						else if (arr[i][j] == arr[k][j]) {
							arr[k][j] = 0;
							arr[i][j] = arr[i][j] * 2;
							break;
						}
					}

			}
		}
		for (int j = 0; j < n; j++) {
			//0 채워주기
			for (int i = 1; i < n; i++) {
				if (arr[i][j] != 0)
					for (int k = i - 1; k >= 0; k--) {
						if (k == 0 && arr[k][j] == 0) {
							arr[k][j] = arr[i][j];
							arr[i][j] = 0;
						}
						else if (arr[k][j] == 0) continue;
						else if (k + 1 != i && arr[k][j] != 0) {
							arr[k + 1][j] = arr[i][j];
							arr[i][j] = 0;
							break;
						}
						else if (k + 1 == i && arr[k][j] != 0) break;
					}
			}
		}
	}
	//하
	else if (mode == 1) {
		for (int j = 0; j < n; j++) {
			//합치기
			for (int i = n - 1; i >= 1; i--) {
				if (arr[i][j] != 0)
					for (int k = i - 1; k >= 0; k--) {
						if (arr[i][j] != arr[k][j] && arr[k][j] == 0) continue;
						else if (arr[i][j] != arr[k][j] && arr[k][j] != 0)break;
						else if (arr[i][j] == arr[k][j]) {
							arr[k][j] = 0;
							arr[i][j] = arr[i][j] * 2;
							break;
						}
					}
			}
		}
		for (int j = 0; j < n; j++) {
			//0 채워주기
			for (int i = n - 2; i >= 0; i--) {
				if (arr[i][j] != 0)
					for (int k = i + 1; k < n; k++) {
						if (k == n - 1 && arr[k][j] == 0) {
							arr[k][j] = arr[i][j];
							arr[i][j] = 0;
							break;
						}
						else if (arr[k][j] == 0) continue;
						else if (k - 1 != i && arr[k][j] != 0) {
							arr[k - 1][j] = arr[i][j];
							arr[i][j] = 0;
							break;
						}
						else if (k - 1 == i && arr[k][j] != 0) break;
					}
			}
		}
	}
	//좌
	else if (mode == 2) {
		for (int i = 0; i < n; i++) {
			//합치기
			for (int j = n - 1; j >= 1; j--) {
				if (arr[i][j] != 0)
					for (int k = j - 1; k >= 0; k--) {
						if (arr[i][k] != arr[i][j] && arr[i][k] == 0) continue;
						else if (arr[i][k] != arr[i][j] && arr[i][k] != 0) break;
						else if (arr[i][k] == arr[i][j]) {
							arr[i][k] = 0;
							arr[i][j] = arr[i][j] * 2;
							break;
						}
					}
			}
		}
		for (int i = 0; i < n; i++) {
			//0 채워주기
			for (int j = n - 2; j >= 0; j--) {
				if (arr[i][j] != 0)
					for (int k = j + 1; k < n; k++) {
						if (k == n - 1 && arr[i][k] == 0) {
							arr[i][k] = arr[i][j];
							arr[i][j] = 0;
						}
						else if (arr[i][k] == 0) continue;
						else if (k - 1 != j && arr[i][k] != 0) {
							arr[i][k - 1] = arr[i][j];
							arr[i][j] = 0;
							break;
						}
						else if (k - 1 == j && arr[i][k] != 0)break;
					}
			}
		}
	}
	//우
	else {
		for (int i = 0; i < n; i++) {
			//합치기
			for (int j = 0; j < n - 1; j++) {
				if (arr[i][j] != 0)
					for (int k = j + 1; k < n; k++) {
						if (arr[i][k] != arr[i][j] && arr[i][k] == 0) continue;
						else if (arr[i][k] != arr[i][j] && arr[i][k] != 0) break;
						else if (arr[i][j] == arr[i][k]) {
							arr[i][k] = 0;
							arr[i][j] = arr[i][j] * 2;
							break;
						}
					}
			}
			//0 채워주기
			for (int j = 1; j < n; j++) {
				if (arr[i][j] != 0)
					for (int k = j - 1; k >= 0; k--) {
						if (k == 0 && arr[i][k] == 0) {
							arr[i][k] = arr[i][j];
							arr[i][j] = 0;
						}
						else if (arr[i][k] == 0) continue;
						else if (k + 1 != j && arr[i][k] != 0) {
							arr[i][k + 1] = arr[i][j];
							arr[i][j] = 0;
							break;
						}
						else if (k + 1 == j && arr[i][k] != 0) break;
					}
			}
		}
	}

	//들어올때랑 나올때랑 같은지 확인
	bool end_same = true;
	for (int i = 0; i < n; i++) {
		if (!end_same) break;
		for (int j = 0; j < n; j++) {
			if (arr_copy[i][j] != arr[i][j]) {
				end_same = false;
				break;
			}
		}
	}
	if (end_same) return 1;
	else return 0;
}
void recur(int mode, int cnt, int arr[][20]) {

	if (cnt == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans = max(ans, arr[i][j]);
			}
		}

		return;
	}

	int arr_copy[20][20];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr_copy[i][j] = arr[i][j];
		}
	}

	int visit = arr_move(mode, arr_copy);
	////debug
	//cout << "cnt : " << cnt+1 << "\n";
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << arr_copy[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n";
	if (visit == 0 || mode != 0)recur(0, cnt + 1, arr_copy);
	if (visit == 0 || mode != 1)recur(1, cnt + 1, arr_copy);
	if (visit == 0 || mode != 2)recur(2, cnt + 1, arr_copy);
	if (visit == 0 || mode != 3)recur(3, cnt + 1, arr_copy);
}
int main() {

	//	int arr[20][20] = { {2,2,0,0},{1,2,0,0},{2,2,0,0},{4,2,1,1} };

	cin >> n;
	int arr[20][20];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	recur(3, 0, arr);
	recur(0, 0, arr);
	recur(1, 0, arr);

	recur(2, 0, arr);



	cout << ans;
	return 0;
}