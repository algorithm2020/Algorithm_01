#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, L, R;
int popular[50][50];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool isRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}
int visit[50][50]; //dfs 도는데 필요한 visit
int visit2[50][50];
int num_of_nation = 0;//한 연합에서 나라의 개수
int union_ = 1;
int dfs(vector<vector<int>>&connect, int x, int y) {
	visit[x][y] = union_;
	int sum_popular = popular[x][y];
	int nation = x * n + y;
	for (auto it = connect[nation].begin(); it != connect[nation].end(); it++) {
		int nx = (*it) / n;
		int ny = *it%n;
		if (visit[nx][ny] == 0) {
			sum_popular += dfs(connect, nx, ny);
			num_of_nation++;
		}
	}
	return sum_popular;
}

void dfs2(vector<vector<int>>&connect, int x, int y, int avg_pop) {
	int nation = x * n + y;
	visit2[x][y] = 1;
	popular[x][y] = avg_pop;
	for (auto it = connect[nation].begin(); it != connect[nation].end(); it++) {
		int nx = (*it) / n;
		int ny = *it%n;
		if (visit2[nx][ny] == 0 && visit[nx][ny] == visit[x][y]) {
			dfs2(connect, nx, ny, avg_pop);
		}
	}
}
int main() {
	cin >> n >> L >> R;
	FOR(i, n) {
		FOR(j, n) {
			cin >> popular[i][j];
		}
	}
	int ans = 0;//인구이동 횟수
	while (1) {
		int visited[50][50] = {};
		vector<vector<int>>connect(2500);
		memset(visit, 0, sizeof(visit));
		memset(visit2, 0, sizeof(visit2));
		//인구이동 할 수 있는 나라 국경선 개방하기
		FOR(i, n) {
			FOR(j, n) {
				if (visited[i][j] == 0) {
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];

						if (isRange(nx, ny)) {
							int diff = abs(popular[i][j] - popular[nx][ny]);
							if (diff >= L && diff <= R)	connect[i*n + j].push_back(nx*n + ny);
						}
					}
					visited[i][j] = 1;
				}

			}
		}
		union_ = 1;
		//연합구하기
		FOR(i, n) {
			FOR(j, n) {
				if (visit[i][j] == 0 && connect[i*n + j].size() != 0) {
					num_of_nation = 1;
					int pop = dfs(connect, i, j);
					pop /= num_of_nation;
					union_++;
					//연합 이동
					dfs2(connect, i, j, pop);
				}
			}
		}
		if (union_ == 1) {
			cout << ans;
			break;

		}
		ans++;
	}
	return 0;
}