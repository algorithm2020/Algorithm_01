#include <bits/stdc++.h>
using namespace std;
int w, h;
int arr[50][50];
int visited[50][50];
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
struct Node {
	int x, y;
};
queue<Node>q;
bool isRange(int x, int y) {
	return x >= 0 && x < h && y >= 0 && y < w;
}
void bfs(int x, int y) {
	q.push({ x,y });
	visited[x][y] = 1;
	while (!q.empty()) {
		int xx = q.front().x;
		int yy = q.front().y;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (isRange(nx, ny) && visited[nx][ny] == 0 && arr[nx][ny] == 1) {
				visited[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	cin >> w >> h;
	while (w != 0 && h != 0) {
		memset(visited, 0, sizeof(visited));
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
			}
		}
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (visited[i][j] == 0 && arr[i][j] == 1) {
					bfs(i, j);
					cnt++;
				}

			}
		}
		cout << cnt << "\n";
		cin >> w >> h;
	}
	return 0;
}