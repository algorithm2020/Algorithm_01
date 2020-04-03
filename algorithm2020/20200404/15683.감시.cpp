#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
vector<pair<int, int>>cctv;
int n, m, cctv_cnt = 0;
int arr[9][9];
int copy_[9][9];
int visited[8][6][4]; //cctv i개중 j번 cctv 중 k번째 모드

int d[6][4][4][2] = {
	{},
	{{{0,1},{0,0},{0,0},{0,0}}, {{1,0},{0,0},{0,0},{0,0}},{{0,-1},{0,0},{0,0},{0,0}},{{-1,0},{0,0},{0,0},{0,0}} }, //1
	{ {{0,1},{0,-1},{0,1},{0,0}},{{1,0},{-1,0},{0,1},{0,0}},{{0,1},{0,-1},{0,1},{0,0}},{{1,0},{-1,0},{0,1},{0,0}} }, // 2
	{ {{-1,0},{0,1},{0,0},{0,0}},{{0,1},{1,0},{0,0},{0,0}} ,{{-1,0},{0,-1},{0,0},{0,0}},{{1,0},{0,-1},{0,0},{0,0}} }, //3
	{ { {0,1},{1,0},{0,-1},{0,0} },{{0,1},{1,0},{-1,0},{0,0}},{{0,1},{0,-1},{-1,0},{0,0} },{{1,0},{0,-1},{-1,0},{0,0} } }, //4
	{ {{0,1},{1,0},{0,-1},{-1,0} },{{0,1},{1,0},{0,-1},{-1,0} },{{0,1},{1,0},{0,-1},{-1,0} } ,{{0,0},{0,0},{0,0},{0,0}}} //5
};
int ans = 100;
int sz[6][3] = { {0,0,0}, { 4,1,2 },{ 2,2,2 }, { 4,2,2 }, { 4,3,2 }, { 1,4,2 } };
bool isRange(int x, int y, int arr[][9]) {
	return x >= 0 && y >= 0 && x < n && y < m && arr[x][y] != 6;
}
//cnt : 방향이 정해진 cctv 개수
// L : cctv 번호
void dfs(int cnt, int L, int arr2[][9], int cpy[][9]) {
	int arr[9][9];
	int copy_[9][9];
	memcpy(arr, arr2, sizeof(arr));
	memcpy(copy_, cpy, sizeof(copy_));
	if (L == 100) {
		int X = 0;
		FOR(i, n) {
			FOR(j, m) {
				if (arr[i][j] == 0) X++;
			}
		}
		ans = min(ans, X);

		return;
	}
	memcpy(copy_, arr, sizeof(copy_));
	FOR(i, sz[L][0]) {
		if (visited[cnt][L][i] == 0) {
			visited[cnt][L][i] = 1;
			FOR(j, sz[L][1]) {
				int x = cctv[cnt].first;
				int y = cctv[cnt].second;
				int nx = x + d[L][i][j][0];
				int ny = y + d[L][i][j][1];
				while (isRange(nx, ny, arr)) {
					if (!(arr[nx][ny] > 0 && arr[nx][ny] < 6)) { //cctv가 아니면
						arr[nx][ny] = 10; //cctv가 보고 있다는 의미
					}
					nx += d[L][i][j][0];
					ny += d[L][i][j][1];
				}
			}
		}
		dfs(cnt + 1, arr[cctv[cnt + 1].first][cctv[cnt + 1].second], arr, copy_);
		memcpy(arr, copy_, sizeof(copy_));
		visited[cnt][L][i] = 0;
	}
}

int main() {
	cin >> n >> m;
	FOR(i, n) {
		FOR(j, m) {
			cin >> arr[i][j];
			copy_[i][j] = arr[i][j];
			if (arr[i][j] > 0 && arr[i][j] < 6) {
				cctv_cnt++;
				cctv.push_back({ i,j });
			}
		}
	}
	cctv.push_back({ 8,8 });
	arr[8][8] = 100;
	copy_[8][8] = 100;
	dfs(0, arr[cctv[0].first][cctv[0].second], arr, copy_);
	cout << ans;
	return 0;
}