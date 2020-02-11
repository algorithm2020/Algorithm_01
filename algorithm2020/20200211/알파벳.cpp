#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int r, c;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 }; //�Ʒ� �� ������ ���� ��
vector<vector<char>>v(20,vector<char>(20));
int visited[20][20];
int max_cnt = 0;
void dfs(int i,int j,vector<int>visit,int cnt) {
	visited[i][j] = 1;
	//4���⿡ ���� �湮
	for (int ii = 0; ii < 4; ii++) {
		int x = dx[ii]+i;
		int y = dy[ii]+j;
		if (x < 0 || y < 0 || x >= r || y >= c) continue;
		int alphabet_pos = v[x][y] - 65;
		//4������ ��� ��ȿ�ϰ�
		//�湮�� �� ���� �����̾���ϸ�
		//������ ���ĺ��� �湮���� �������
		if (visited[x][y] == 0 && visit[alphabet_pos]==0) {
			visit[alphabet_pos] = 1;
			dfs(x, y, visit,cnt+1);
			//�湮�Ϸ��� �ʱ�ȭ
			visited[x][y] = 0;
			visit[alphabet_pos] = 0;
		}
	}

	max_cnt = max(max_cnt, cnt);
	return;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> v[i][j];
		}
	}
	vector<int>visit(26, 0);
	visit[v[0][0] - 65] = 1;
	dfs(0, 0, visit,1);
	cout << max_cnt;
	return 0;
}