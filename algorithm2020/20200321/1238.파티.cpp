#include <bits/stdc++.h>
#define FOR(i,n) for(int i=1;i<=n;i++)
#define MAX 1e6
using namespace std;
int n;
int m, x;
int arr[1001][1001];
int dist[1001][1001];
int main() {
	cin >> n >> m >> x;
	FOR(i, n) {
		FOR(j, n) {
			if (i == j) {
				dist[i][j] = 0;
			}
			else {
				dist[i][j] = MAX;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int start, end, val;
		cin >> start >> end >> val;
		dist[start][end] = val;
	}

	FOR(mid, n) {
		FOR(from, n) {
			FOR(to, n) {
				if (dist[from][to] > dist[from][mid] + dist[mid][to]) {
					dist[from][to] = dist[from][mid] + dist[mid][to];
				}
			}
		}
	}
	int ans = 0;
	FOR(i, n) {
		if (ans < dist[i][x] + dist[x][i]) {
			ans = dist[i][x] + dist[x][i];
		}
	}
	cout << ans;
	return 0;
}