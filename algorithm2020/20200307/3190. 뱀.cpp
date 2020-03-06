#include <bits/stdc++.h>
using namespace std;
int n, k, l;
int arr[100][100];
struct Node {
	int x, y; //�Ӹ���ǥ
	int t, dir;//����ð��� �Ӹ�����
};
vector<pair<int, int>>v;//�Ӹ������� �ð��� ������ ����
queue<Node>cur; //���� �Ӹ� ��ġ�� �ð�,�Ӹ�����
vector<pair<int, int>>route;//�̵����
int visited[100][100];
int ans = 0;
bool isRange(int x, int y) {
	return x >= 0 && x < n&&y >= 0 && y < n &&visited[x][y] != 1;
}
bool end_flag = false;
int get_move(int nx, int ny, int t, int cnt, int dir) {
	//������ �� ���� ���������̸� ����
	if (!isRange(nx, ny)) {
		ans = t + 1;
		end_flag = true;
		return 0;
	}
	route.push_back({ nx,ny });
	//����� �ƴ� ���
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

// �� �� �� �� ������ 0 1 2 3
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
	int cnt = 0;//����
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
		//�Ӹ��̵�
		switch (dir) {
			//��
		case 0:
			cnt = get_move(x, y + 1, t, cnt, 0);
			break;
			//��
		case 1:
			cnt = get_move(x - 1, y, t, cnt, 1);
			break;
			//��
		case 2:
			cnt = get_move(x, y - 1, t, cnt, 2);
			break;
			//��
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
		visited[a][b] = 2; //�����ġ
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