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
int dy[4] = { 0,1,0,-1 }; //하 좌 상 우

vector<vector<char>>v(12, vector<char>(6));
queue<node>q;
int visited[12][6];

bool isRange(int i, int j) {
	return (i >= 0 && i < n && j < m && j >= 0 && visited[i][j] == 0);
}
//구슬 삭제
void delColor(vector<pair<int, int>>vv) {
	for (auto it = vv.begin(); it != vv.end(); it++) {
		int x = it->first;
		int y = it->second;
		v[x][y] = '.';
	}
}
//구슬 내려오기
void down(int x, int y) {

	//특정 열이 비어있으면
	if (v[x][y] == '.')
	{
		for (int i = 0; i < x; i++) {
			v[x - i][y] = v[x - i - 1][y];
		}
		v[0][y] = '.';
	}
}
//visited 초기화
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

	//같은 색이 4개이상이면 제거대상에 넣는다.
	if (ret.size() >= 4) {
		return ret;
	}
	//같은 색이 3개이하이면 제거대상이 아니다
	else {
		ret.clear();
		return ret;
	}
}

int main() {
	//입력받기
	FOR(i, n) {
		FOR(j, m) {
			cin >> v[i][j];
		}
	}

	int ans = 0;
	do {
		vector < vector<pair<int, int>>>candidate; //삭제후보 구슬 묶음
		init();
		//모든 점에 대해서 4개이상인것 찾기
		int vec_cnt = 0;
		FOR(i, n) {
			FOR(j, m) {
				if (visited[i][j] == 0 && v[i][j] != '.') {
					vector<pair<int, int>>puyo = bfs(i, j); //구슬묶음
					if(puyo.size() == 0) continue;
					candidate.push_back(puyo);
					sort(candidate[vec_cnt].begin(), candidate[vec_cnt].end()); 
					vec_cnt++;
					
				}
				
			}
		}

		if (candidate.size() == 0) break;

		for(auto iter=candidate.begin();iter!=candidate.end();iter++){
			//위 구슬부터 삭제
			delColor(*iter);
			for (auto it = iter->begin(); it != iter->end(); it++) {
				int x = it->first;
				int y = it->second;
				down(x, y); //남은 자리 채우기
			}

		}
		ans++;
	} while (1);

	cout << ans;
	return 0;
}