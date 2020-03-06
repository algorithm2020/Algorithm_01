#include <bits/stdc++.h>
using namespace std;
int n, k, l;
int arr[100][100];
struct Node {
	int x, y; //머리좌표
	int t, dir;//현재시간과 머리방향
};
vector<pair<int, int>>v;//머리돌리는 시간과 돌리는 방향
queue<Node>cur; //현재 머리 위치와 시간,머리방향
vector<pair<int, int>>route;//이동경로
int visited[100][100];
int ans = 0;
bool isRange(int x, int y) {
	return x >= 0 && x < n&&y >= 0 && y < n &&visited[x][y] != 1;
}
bool end_flag = false;
int get_move(int nx, int ny, int t, int cnt, int dir) {
	//다음에 갈 곳이 비정상적이면 종료
	if (!isRange(nx, ny)) {
		ans = t + 1;
		end_flag = true;
		return 0;
	}
	route.push_back({ nx,ny });
	//사과가 아닐 경우
	if (visited[nx][ny] != 2) {
		int tail_nx = route[cnt].first;
		int tail_ny = route[cnt].second;
		visited[tail_nx][tail_ny] = 0;
		cnt++;
	}
	visited[nx][ny] = 1;

	cur.push({ nx,ny,t + 1,dir });
	return cnt;
}

// 우 상 좌 하 순으로 0 1 2 3
int rotate(int cur_dir, char dir) {
	if (dir == 'L') cur_dir = (cur_dir + 1) % 4;
	else cur_dir = (cur_dir - 1 + 4) % 4;
	return cur_dir;
}


void bfs() {

	cur.push({ 0,0,0,0 });
	route.push_back({ 0,0 });
	visited[0][0] = 1;
	auto it = v.begin();
	int cnt = 0;//꼬리
	while (!cur.empty()) {
		int x = cur.front().x;
		int y = cur.front().y;
		int t = cur.front().t;
		int dir = cur.front().dir;
		cur.pop();

		if (it != v.end() && it->first == t) {
			dir = rotate(dir, it->second);
			it++;
		}
		//머리이동
		switch (dir) {
			//우
		case 0:
			cnt = get_move(x, y + 1, t, cnt, 0);
			break;
			//상
		case 1:
			cnt = get_move(x - 1, y, t, cnt, 1);
			break;
			//좌
		case 2:
			cnt = get_move(x, y - 1, t, cnt, 2);
			break;
			//하
		case 3:
			cnt = get_move(x + 1, y, t, cnt, 3);
			break;
		default:break;
		}

		if (end_flag) return;
	}
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		a -= 1, b -= 1;
		visited[a][b] = 2; //사과위치
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int a;
		char dir;
		cin >> a >> dir;
		v.push_back({ a,dir });
	}
	bfs();
	cout << ans;
	return 0;
}