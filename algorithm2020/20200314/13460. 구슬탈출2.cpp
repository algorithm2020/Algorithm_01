#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

char arr[10][10];
int visited[10][10][10][10];

int n, m;
int dx[4] = { 1, -1,0,0 };
int dy[4] = { 0,0,1,-1 }; //�� �� �� ��
int ansx, ansy;

struct info {
	//R��ǥ
	int x, y, cnt;

	//B��ǥ
	int x2, y2;
};
queue <info>q;

bool End = false;
int checkMove(int x, int y) {
	return x <= 0 || x >= n - 1 || y <= 0 || y >= m - 1;

}

int bfs() {

	//R�� ���� ��
	int x, y, cnt = 0;

	//B�� ���� ��
	int x2, y2;

	while (!q.empty()) {


		x = q.front().x;
		y = q.front().y;
		cnt = q.front().cnt;

		x2 = q.front().x2;
		y2 = q.front().y2;
		q.pop();

		//Ż��
		if (arr[x][y] == 'O' && cnt <= 10) {
			End = true;
			return cnt;
		}
		if (cnt > 10) {
			return -1;
		}


		//***************************************RED �̵��ϱ� 4����
		//���� �̵��� ���� ���� �ƴϸ� �� ����
		//���ϵ�����
		for (int i = 0; i < 4; i++) {
			int rx = x;
			int ry = y;
			int bx = x2;
			int by = y2;

			while (1) {
				rx += dx[i];
				ry += dy[i];
				if (arr[rx][ry] == '#') {
					rx -= dx[i], ry -= dy[i];
					break;
				}
				if (arr[rx][ry] == 'O') break;
			}

			while (1) {
				bx += dx[i];
				by += dy[i];
				if (arr[bx][by] == '#') {
					bx -= dx[i], by -= dy[i];
					break;
				}

				if (arr[bx][by] == 'O') {
					break;
				}
			}

			//B�� ���� �����ϸ� �� ����� �� ������
			if (bx == ansx && by == ansy) continue;

			if (rx == bx && ry == by) {
				switch (i) {
					//��
				case 0:x < x2 ? rx-- : bx--; break;
					//��
				case 1:x < x2 ? bx++ : rx++; break;
					//��
				case 2:y < y2 ? ry-- : by--; break;
					//��
				case 3:y < y2 ? by++ : ry++; break;
				default: break;
				}
			}

			if (visited[rx][ry][bx][by] != 1) {
				info Info = { rx,ry,cnt + 1,bx,by };
				q.push(Info);
				visited[rx][ry][bx][by] = 1;
			}
		}
	}

	if (!End) return -1;
}

int main() {
	cin >> n >> m;
	info Info;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R') {
				Info.x = i;
				Info.y = j;
			}

			if (arr[i][j] == 'B') {
				Info.x2 = i;
				Info.y2 = j;
			}

			if (arr[i][j] == 'O') {
				ansx = i;
				ansy = j;
			}
		}
	}
	visited[Info.x][Info.y][Info.x2][Info.y2] = 1;
	Info.cnt = 0;
	q.push(Info);
	cout << bfs();

	return 0;
}
