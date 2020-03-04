#include <bits/stdc++.h>
using namespace std;
struct Node {
	int x, y, cnt, wallbreak;
};

queue<Node>q;
int arr[1000][1000];
int visited[1000][1000][2]; //마지막은 0이면 안부숨 1이면 부숨
int n, m;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ans = 1e7;
bool end_flag = false;
bool isRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}
void bfs() {
	q.push({ 0,0,0,0 });
	visited[0][0][0] = 1;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		int wallbreak = q.front().wallbreak;
		q.pop();

		if (x == n - 1 && y == m - 1) {
			end_flag = true;
			ans = min(ans, cnt + 1);
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isRange(nx, ny)) {

				//벽이 있어서 뚫은 경우
				if (visited[nx][ny][1] == 0 && wallbreak == 0 && arr[nx][ny] == 1) {
					visited[nx][ny][1] = 1;
					q.push({ nx,ny,cnt + 1,1 });
				}

				//벽이 없는데 벽 뚫어본 경우
				else if (arr[nx][ny] == 0 && wallbreak == 1 && visited[nx][ny][1] == 0) {
					visited[nx][ny][1] = 1;
					q.push({ nx,ny,cnt + 1,wallbreak });
				}

				//벽이 없는데 벽 뚫어보지 않은 경우
				else if (arr[nx][ny] == 0 && wallbreak == 0 && visited[nx][ny][0] == 0) {
					visited[nx][ny][0] = 1;
					q.push({ nx,ny,cnt + 1,wallbreak });
				}
			}

		}
	}

	if (!end_flag) ans = -1;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	bfs();
	printf("%d", ans);
	return 0;
}