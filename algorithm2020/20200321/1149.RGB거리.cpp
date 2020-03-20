#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
int n;
int arr[1000][1000];
int d[1000][3]; //i번째집의 색이 j이고 위의 집의 색이 k일때 드는 비용
int color[3][2] = { {1,2},{0,2},{0,1} }; //R, G, B
int ans = 0;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	FOR(i, n) {
		FOR(j, 3) {
			cin >> arr[i][j];
		}
	}

	FOR(i, 3) {
		d[0][i] = arr[0][i];
	}

	for (int i = 1; i < n; i++) {
		FOR(j, 3) {
			d[i][j] = min(d[i - 1][color[j][0]], d[i - 1][color[j][1]]) + arr[i][j];
		}
	}
	int ans = 1e8;
	FOR(i, 3) ans = min(ans, d[n - 1][i]);
	cout << ans;
	return 0;
}