#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
int gear[6][8];
int k, rotation;
int surround[5][2] = { {0,0},{0,2},{1,3},{2,4},{4,0} };
void rotate_inner(int num, int dir) {
	int tmp[8];

	FOR(i, 8) tmp[i] = gear[num][i];
	FOR(i, 8)gear[num][(i + dir + 8) % 8] = tmp[i];
}
int visited[6];
void rotate(int num, int dir) {
	visited[num] = 1;
	if (num == 0 || num == 5) return;
	int left = gear[num][6];
	int right = gear[num][2];

	rotate_inner(num, dir);
	if (visited[num - 1] == 0 && left != gear[num - 1][2]) {
		rotate(num - 1, (~dir) + 1);
	}
	if (visited[num + 1] == 0 && right != gear[num + 1][6]) {
		rotate(num + 1, (~dir) + 1);
	}
}

int main() {
	FOR(i, 6) {
		if (i == 0 || i == 5) {
			FOR(j, 8) gear[i][j] = 0;
			continue;
		}
		FOR(j, 8) {
			scanf("%1d", &gear[i][j]);
		}
	}

	scanf("%d", &k);
	while (k--) {
		memset(visited, 0, sizeof(visited));
		int num, dir;
		scanf("%d %d", &num, &dir);
		rotate(num, dir);
	}
	int ans = 0;
	FOR(i, 6) {
		if (i == 0 || i == 5)continue;
		ans += (gear[i][0] == 0) ? 0 : pow(2, i - 1);
	}
	printf("%d", ans);
	return 0;
}