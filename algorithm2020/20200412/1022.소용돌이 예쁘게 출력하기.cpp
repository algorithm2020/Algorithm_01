#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
int arr[50][5];
int n, m;
int r1, r2, c1, c2;
int d[8][2] = { {0,1},{-1,1},{-1,0},{-1,1},{0,-1},{1,-1},{1,0},{1,1} };
bool check(int nx, int ny) {
	return nx <= n && nx >= 0 && ny >= 0 && ny <= m;
}

int all_cnt = 0;
int max_num;
void go(int x, int y) {
	int dir = 0;
	int nx = x , ny = y ;
	int n = 1;
	int val = 2;
	int cnt = 1; //한번에 직진하는 횟수
	while (1) {
		if (all_cnt == 0) break;
		while(n--){
			nx += d[dir][0], ny += d[dir][1];
			if (check(nx, ny)) {
				all_cnt--;
				arr[nx][ny] = val;
				if (all_cnt == 0) max_num = val;
			}
			val++;
		}
		dir = (dir + 2) % 8;
		n = cnt;

		if (all_cnt == 0) break; //탈출조건

		while (n--) {
			nx += d[dir][0], ny += d[dir][1];
			if (check(nx, ny)) {
				all_cnt--;
				arr[nx][ny] = val;
				if (all_cnt == 0) max_num = val;
			}
			val++;
		}
		dir = (dir + 2) % 8;
		n = ++cnt;
	}
	
	
}
int main() {
	cin >> r1 >> c1 >> r2 >> c2;
	n = r2 - r1, m = c2 - c1;
	int x = -r1, y = -c1; //시작좌표
	all_cnt = (n+1) * (m+1);
	if (check(x, y)) {
		all_cnt--;
		arr[x][y] = 1;
	}
	go(x, y);
	
	int max_len = to_string(max_num).size();
	FOR(i, n + 1) {
		FOR(j, m + 1) {
			int cnt = max_len - to_string(arr[i][j]).size();
			while (cnt--) {
				cout << " ";
			}
			cout << arr[i][j]<<" ";
		}
		cout << "\n";
	}
	
	return 0;
}