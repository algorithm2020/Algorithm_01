#include <bits/stdc++.h>
using namespace std;
int r, c;
char v[50][50];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 }; //상하좌우
int visited[50][50]; //고슴도치 이동:1 물이동 :2

pair<int, int>exit_;
struct Node {
	int x, y, cnt;
};

queue<Node>q;
queue<pair<int, int>>wt;//물이동 방향
int isRange(int x, int y) {
	return x >= 0 && x < r && y >= 0 && y < c;
}
queue<pair<int, int>> water() {
	queue<pair<int, int>>new_wt;
	while (!wt.empty()) {
		int x = wt.front().first;
		int y = wt.front().second;
		wt.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isRange(nx, ny) && visited[nx][ny] == 0 && v[nx][ny] != 'X' && v[nx][ny] != 'D') { //범위 내에 있고 물이 방문한적없고 돌도 아니어야함
				visited[nx][ny] = 2;
				v[nx][ny] = '*';
				new_wt.push({ nx,ny });
			}
		}
	}
	return new_wt;
}
void bfs() {
	while (1) {
		//물이동
		wt = water();
		int size_ = q.size();
		if (size_ == 0) break;
		while (size_--) {
			int x = q.front().x;
			int y = q.front().y;
			int cnt = q.front().cnt;
			q.pop();
			//탈출 조건
			if (x == exit_.first&&y == exit_.second) {
				cout << cnt;
				return;
			}
			//고슴도치 이동
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (isRange(nx, ny) && visited[nx][ny] == 0 && v[nx][ny] != 'X' && v[nx][ny] != '*') { //범위 내에 있고 방문한적없고 돌,물도 아니어야함
					visited[nx][ny] = 1;
					q.push({ nx,ny,cnt + 1 });
				}
			}
		}
	}
	cout << "KAKTUS\n";
	return;
}
int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> v[i][j];

			if (v[i][j] == 'D') {
				exit_ = { i,j };
			}
			else if (v[i][j] == 'S') {
				q.push({ i,j,0 });
				visited[i][j] = 1;
			}
			else if (v[i][j] == '*') {
				wt.push({ i,j });
				visited[i][j] = 2;
			}
		}
	}

	bfs();
	return 0;
}