#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int arr[13];
int visited[13];
int t = -1;

void recur(int n, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < t; i++) {
			if (visited[i] == 1)
				cout << arr[i] << " ";
		}
		cout << "\n";

	}
	for (int i = n; i < t; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			recur(i, cnt + 1);
			visited[i] = 0;
		}
	}
	return;
}

int main() {
	while (t != 0) {
		cin >> t;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < t; i++) {
			cin >> arr[i];
		}
		recur(0, 0);
		cout << "\n";
	}
	return 0;
}