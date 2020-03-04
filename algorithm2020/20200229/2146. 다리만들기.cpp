#include <bits/stdc++.h>
using namespace std;
int n;
int land[100][100]; //1: ���� 0: �ٴ�
int arr2[100][100];
int visited[100][100]; //0 :�̹湮
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ans = 1e8;
struct Node {
	int x, y;
	int cnt; //�ٸ� �����µ� �ʿ��� �ٸ� ��
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

//����ȣ �ű��
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
			//�� ��ġ�� �ٸ�, ���� ��ġ�� �ٸ�
			if (arr2[nx][ny] != 0 && arr2[x][y] != 0) {
				ans = min(ans, arr2[nx][ny] + arr2[x][y]);
			}
			//�� ��ġ�� ��, ���� ��ġ�� �ٸ�
			else if (arr2[nx][ny] != 0 && arr2[x][y] == 0) {
				ans = min(ans, arr2[nx][ny]);
			}
			//�� ��ġ�� �ٸ�, ���� ��ġ�� ��
			else if (arr2[nx][ny] == 0 && arr2[x][y] != 0) {
				ans = min(ans, arr2[x][y]);
			}
			//�� ��ġ�� �� ���� ��ġ�� ���� ���� ����
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
		//�ֺ� Ȯ��
		check(x, y);

		for (int ii = 0; ii < 4; ii++) {
			int nx = x + dx[ii];
			int ny = y + dy[ii];
			if (isRange(nx, ny) && visited[nx][ny] == 0) {
				visited[nx][ny] = 1;
				//�߰��� ���� �ٴ��̸� �ٸ� ����
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