#include <bits/stdc++.h>
using namespace std;
int d[500][500];
int arr[500][500];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n;
struct Node {
	int x, y;
	int val;
};
vector<Node>ar;
bool cmp(Node &a, Node &b) {
	return a.val > b.val;
}

bool isRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

int recur(int x, int y) {
	if (d[x][y] != 0) return d[x][y];

	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (isRange(nx, ny) && arr[nx][ny] > arr[x][y]) d[x][y] = max(recur(nx, ny) + 1, d[x][y]);
	}
	if (d[x][y] == 0)return 1;
	else return d[x][y];
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			ar.push_back({ i,j,a });
			arr[i][j] = a;
		}
	}
	sort(ar.begin(), ar.end(), cmp);
	int sz = ar.size();
	for (int i = 0; i < sz; i++) {
		recur(ar[i].x, ar[i].y);
	}
	int ans = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(ans, d[i][j]);
		}
	}
	cout << ans;
	return 0;
}