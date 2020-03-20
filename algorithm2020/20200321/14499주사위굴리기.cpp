#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, m, k;
int arr[20][20];
int order[1000];
/*
  0
4 1 5
  2
  3
*/
int motion[5][6] = {
	{0,0,0,0,0,0}, //쓰레기
	{0,4,2,5,3,1}, //동
	{0,5,2,4,1,3}, //서
	{1,2,3,0,4,5}, //북
	{3,0,1,2,4,5} //남
};
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 }; //x 동 서 북 남 순
int dice[6] = {};
bool isRange(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}
int main() {
	int x, y;
	cin >> n >> m >> x >> y >> k;
	FOR(i, n) {
		FOR(j, m) {
			cin >> arr[i][j];
		}
	}

	FOR(i, k) {
		cin >> order[i];
	}

	FOR(i, k) {
		x += dx[order[i]];
		y += dy[order[i]];
		if (!isRange(x, y)) {
			x -= dx[order[i]];
			y -= dy[order[i]];
			continue;
		}
		int tmp[6];
		FOR(j, 6) tmp[j] = dice[motion[order[i]][j]];
		if (arr[x][y] == 0) {
			arr[x][y] = tmp[3];
		}
		else {
			tmp[3] = arr[x][y];
			arr[x][y] = 0;
		}
		FOR(j, 6) dice[j] = tmp[j];
		cout << dice[1] << "\n";
	}
	return 0;
}