#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
#include <cstring>
using namespace std;

struct node {
	int x;
	int y;
	int val;
};
int map[300][300];
queue<pair<int, int>>q; //����ƴѰ� ���� ť
int n, m;
int visited[300][300]; //�ش���ǥ �湮����
int q_size;
int dx[4] = { -1,1,0,0 };//�� �Ʒ� ������ ���� ��
int dy[4] = { 0,0,1,-1 };
int max_cnt = 0;
bool isRange(int i, int j) {
	return (i >= 0 && j >= 0 && j < m && i < n);
}
queue<pair<int, int>> getAfterYear(queue<pair<int, int>>&q) {
	queue<pair<int, int>>new_q;
	int size_ = q.size();
	vector<node>tmp_v; //������ΰ� �ӽ�����
	while (!q.empty()) { //���� ���� ��ǥ�� �޾ƿͼ� 1����� �����ϱ�
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int new_i = dx[i] + x;
			int new_j = dy[i] + y;
			if (isRange(new_i, new_j) && map[new_i][new_j] == 0) cnt++;
		}
		int new_var = map[x][y] - cnt;
		if (new_var > 0) {
			tmp_v.push_back({ x,y,new_var });
			new_q.push({ x, y });
		}
		else {
			tmp_v.push_back({ x,y,0 });
		}
	}

	for (auto it = tmp_v.begin(); it != tmp_v.end(); it++) {
		int x = it->x;
		int y = it->y;
		map[x][y] = it->val;
	}
	return new_q;
}

void bfs(queue<pair<int, int>>q) {

	int cnt = 0;
	while (!q.empty()) {


		int x = q.front().first;
		int y = q.front().second;
		visited[x][y] = 1;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int new_i = dx[i] + x;
			int new_j = dy[i] + y;
			//ť �ٵ��鼭 ������ üũ
			if (isRange(new_i, new_j) && visited[new_i][new_j] == 0) {
				q.push({ new_i,new_j });
				cnt++;
			}
		}
		if (cnt == q_size) break;
	}


}

bool endflag = false;
int dfs(int x, int y, int seg, int cnt) { //(x,y) ���׸�Ʈ �� ,������ ���� ��
	if (cnt == q_size) {
		endflag = true;
		return cnt;
	}

	for (int i = 0; i < 4; i++) {
		//4���⿡ ���� dfs
		int new_i = dx[i] + x;
		int new_j = dy[i] + y;
		if (isRange(new_i, new_j) && !endflag && map[new_i][new_j] != 0) {
			cnt = dfs(new_i, new_j, seg, cnt + 1);

		}
	}
	return cnt;
}
int dfs_cnt = 0;
bool dfs2(int x, int y, int seg, int cnt) { //(x,y) ���׸�Ʈ �� ,������ ���� ��
	dfs_cnt++;
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		//4���⿡ ���� dfs
		int new_i = dx[i] + x;
		int new_j = dy[i] + y;
		if (isRange(new_i, new_j) && map[new_i][new_j] != 0 && visited[new_i][new_j] == 0) {
			dfs2(new_i, new_j, seg, cnt + 1);
		}
	}
	if (dfs_cnt == q_size) return true;
	return false;
}
void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
		}
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0) q.push({ i,j });
		}
	}

	int year = 0;

	while (1) { //�����
		int segment = 0; //����
		q_size = q.size(); //�����ִ� ���� ��
		if (q_size == 0) {
			cout << 0;
			return 0;
		}
		while (!q.empty()) { //���� ������ ���鼭 dfs�� ������ ã��
			init();
			dfs_cnt = 0;
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (visited[x][y] == 0) {
				//���׸�Ʈ�� �ϳ��̸� �����ط� �Ѿ��
				if (dfs2(x, y, segment, 1)) {
					q.push({ x, y });
					visited[x][y] = 0;
					//cout << "Ż�����\n";
					break;
				}
			}
			q.push({ x, y });
			visited[x][y] = 0;
			segment++;
			if (segment >= 1) break;
		}

		if (segment >= 1) {
			cout << year;
			break;
		}

		q = getAfterYear(q);
		/*cout << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}*/
		year++;

	}

	return 0;
}