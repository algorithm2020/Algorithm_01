#define FOR(i,n) for(int i=0;i<n;i++)
#include <iostream>
#include <queue>
using namespace std;
struct Node {
	int x, y;
	int d; //방향
};
queue<Node>q;
int dir_by_region[4] = { 3,0,1,2 };
int back[4][2] = { {1,0},{0,-1},{-1,0},{0,1} };
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

int n, m;
int visited[51][51];
int main() {
	cin >> n >> m;

	int r, c, d;
	cin >> r >> c >> d;
	q.push({ r, c, d });
	FOR(i, n) {
		FOR(j, m) {
			cin >> visited[i][j];
		}
	}
	int ans = 0;
	while (!q.empty()) {
		int end_flag = false;
		int x = q.front().x;
		int y = q.front().y;
		int d = q.front().d;
		q.pop();
		if (visited[x][y] == 0) {
			visited[x][y] = 2; //청소하기
			ans++;
		}
		int cnt = 0; //주위 본 횟수
		while (1) {
			cnt++;
			int nx = dir[dir_by_region[d]][0] + x;
			int ny = dir[dir_by_region[d]][1] + y;

			if (visited[nx][ny] == 0) {
				q.push({ nx,ny,dir_by_region[d] });
				end_flag = true;
				break;
			}
			//else if (visited[nx][ny] == 1) { continue; }
			else {
				d = dir_by_region[d];

			}

			if (cnt == 4) {
				if (visited[back[d][0] + x][back[d][1] + y] == 2) {
					x = back[d][0] + x;
					y = back[d][1] + y;
					cnt = 0;
				}
				//else if (visited[back[d][0] + x][back[d][1] + y] == 1) {
				else {
					cout << ans;
					return 0;
				}
			}
		}
	}
	return 0;
}