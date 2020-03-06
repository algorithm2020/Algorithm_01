#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>>v(501, vector<int>(501));
int visited[501];
int ans = 0;
queue<pair<int, int>>q;
void bfs() {
	visited[1] = 1;
	q.push({ 1,1 });
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cnt >= 3) continue;

		for (int i = 2; i <= n; i++) {
			if (visited[i] == 1) continue;
			//친구관계이면
			if (i != x && v[x][i] == 1 && visited[i] == 0) {
				ans++;
				visited[i] = 1;
				q.push({ i,cnt + 1 });
			}

		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a][b] = 1;
		v[b][a] = 1;
	}
	//dfs(1, 1);
	bfs();
	cout << ans;
	return 0;
}