#include <bits/stdc++.h>
using namespace std;
int n;
int land[100][100]; //1: 육지 0: 바다
int arr2[100][100];
int visited[100][100]; //0 :미방문
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ans = 1e8;
struct Node {
	int x, y;
	int cnt; //다른 섬가는데 필요한 다리 수
};
queue<Node>q;
vector<pair<int, int>>number;

bool isRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

void dfs(int x, int y, int cnt) {
	arr2[x][y] = cnt;
	for (int ii = 0; ii < 4; ii++) {
		int nx = x + dx[ii];
		int ny = y + dy[ii];
		//if (isRange(nx, ny) && visited[nx][ny] == 0 && arr[nx][ny] == 1) dfs(nx, ny, cnt);
		if (isRange(nx, ny) && land[nx][ny] == 1 && arr2[nx][ny] == 0) dfs(nx, ny, cnt);
	}
}

//섬번호 매기기
void numbering() {
	int cnt = 1;
	for (int i = 0; i < number.size(); i++) {
		int x = number[i].first;
		int y = number[i].second;

		if (arr2[x][y] == 0) {
			dfs(x, y, cnt++);
		}
	}
}

void check(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (isRange(nx, ny) && land[nx][ny] != land[x][y] && land[nx][ny] != 0) {
			//현 위치는 다리, 다음 위치는 다리
			if (arr2[nx][ny] != 0 && arr2[x][y] != 0) {
				ans = min(ans, arr2[nx][ny] + arr2[x][y]);
			}
			//현 위치는 땅, 다음 위치는 다리
			else if (arr2[nx][ny] != 0 && arr2[x][y] == 0) {
				ans = min(ans, arr2[nx][ny]);
			}
			//현 위치는 다리, 다음 위치는 땅
			else if (arr2[nx][ny] == 0 && arr2[x][y] != 0) {
				ans = min(ans, arr2[x][y]);
			}
			//현 위치는 땅 다음 위치도 땅인 경우는 없음
			else if (arr2[nx][ny] == 0 && arr2[x][y] == 0) {
				continue;
			}
		}
	}
}
void bfs2() {
	visited[q.front().x][q.front().y] = land[q.front().x][q.front().y];
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();
		//주변 확인
		check(x, y);

		for (int ii = 0; ii < 4; ii++) {
			int nx = x + dx[ii];
			int ny = y + dy[ii];
			if (isRange(nx, ny) && visited[nx][ny] == 0) {
				visited[nx][ny] = 1;
				//발견한 것이 바다이면 다리 놓기
				if (land[nx][ny] == 0 && arr2[nx][ny] == 0) {
					arr2[nx][ny] = cnt + 1;
					land[nx][ny] = land[x][y];
					q.push({ nx,ny,cnt + 1 });
				}
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> land[i][j];
			if (land[i][j] == 1) {
				number.push_back({ i,j });
			}
		}
	}

	numbering();
	memcpy(land, arr2, sizeof(land));
	memset(arr2, 0, sizeof(arr2));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (land[i][j] != 0) {
				q.push({ i,j,0 });
			}
		}
	}
	bfs2();
	cout << ans;
	return 0;
}