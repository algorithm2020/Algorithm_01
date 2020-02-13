#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

struct node {
	int x, y;
	char color;
	int cnt;
};

int n = 12, m = 6;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; //�� �� �� ��

vector<vector<char>>v(12, vector<char>(6));
queue<node>q;
int visited[12][6];

bool isRange(int i, int j) {
	return (i >= 0 && i < n && j < m && j >= 0 && visited[i][j] == 0);
}
//���� ����
void delColor(vector<pair<int, int>>vv) {
	for (auto it = vv.begin(); it != vv.end(); it++) {
		int x = it->first;
		int y = it->second;
		v[x][y] = '.';
	}
}
//���� ��������
void down(int x, int y) {

	//Ư�� ���� ���������
	if (v[x][y] == '.')
	{
		for (int i = 0; i < x; i++) {
			v[x - i][y] = v[x - i - 1][y];
		}
		v[0][y] = '.';
	}
}
//visited �ʱ�ȭ
void init() {
	FOR(i, n) {
		FOR(j, m) {
			visited[i][j] = 0;
		}
	}
}
vector<pair<int, int>> bfs(int i,int j) {
	vector<pair<int, int>>ret;
	visited[i][j] = 1;
	q.push({ i,j,v[i][j],0 });
	ret.push_back({ i,j });
	int x, y, cnt;
	char color;

	while (!q.empty()) {
		x = q.front().x;
		y = q.front().y;
		cnt = q.front().cnt;
		color = q.front().color;
		q.pop();

		FOR(i, 4) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isRange(nx, ny) && color == v[nx][ny]) {
				visited[nx][ny] = 1;
				ret.push_back({ nx,ny });
				q.push({ nx,ny,color,cnt + 1 });
			}
		}
	}

	//���� ���� 4���̻��̸� ���Ŵ�� �ִ´�.
	if (ret.size() >= 4) {
		return ret;
	}
	//���� ���� 3�������̸� ���Ŵ���� �ƴϴ�
	else {
		ret.clear();
		return ret;
	}
}

int main() {
	//�Է¹ޱ�
	FOR(i, n) {
		FOR(j, m) {
			cin >> v[i][j];
		}
	}

	int ans = 0;
	do {
		vector < vector<pair<int, int>>>candidate; //�����ĺ� ���� ����
		init();
		//��� ���� ���ؼ� 4���̻��ΰ� ã��
		int vec_cnt = 0;
		FOR(i, n) {
			FOR(j, m) {
				if (visited[i][j] == 0 && v[i][j] != '.') {
					vector<pair<int, int>>puyo = bfs(i, j); //��������
					if(puyo.size() == 0) continue;
					candidate.push_back(puyo);
					sort(candidate[vec_cnt].begin(), candidate[vec_cnt].end()); 
					vec_cnt++;
					
				}
				
			}
		}

		if (candidate.size() == 0) break;

		for(auto iter=candidate.begin();iter!=candidate.end();iter++){
			//�� �������� ����
			delColor(*iter);
			for (auto it = iter->begin(); it != iter->end(); it++) {
				int x = it->first;
				int y = it->second;
				down(x, y); //���� �ڸ� ä���
			}

		}
		ans++;
	} while (1);

	cout << ans;
	return 0;
}