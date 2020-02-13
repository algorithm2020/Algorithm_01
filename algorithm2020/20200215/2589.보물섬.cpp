#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
#include <string>
#include <cstring>
#include <utility>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<vector<int>>visited(50, vector<int>(50)); //방문여부
int ans = 0;
vector<vector<char>>v(50, vector<char>(50)); //v[i] first: i->j로 갈때 v[i] second 가 가중치
bool isRange(int i, int j) {
	return (i < n && j < m && i >= 0 && j >= 0 && v[i][j] == 'L');
}

struct node {
	int x;
	int y;
	int dist;
};
queue<node>q;
void bfs(int xx,int yy) {
	visited[xx][yy] = 1;
	q.push({xx,yy,0 });
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dist = q.front().dist;
		q.pop();

		ans = max(dist, ans);
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isRange(nx, ny) && visited[nx][ny] == 0) {
				visited[nx][ny] = 1;
				q.push({ nx,ny,dist + 1 });
			}
		}
	}
	return;
}
void init() {
	FOR(i, n) {
		FOR(j, m) {
			visited[i][j] = 0;
		}
	}
}
int main() {
	cin >> n >> m;
	FOR(i, n) {
		FOR(j, m) {
			cin >> v[i][j];
		}
	}
	vector<pair<int, int>>vv;
	//제일 먼곳 찾기
	FOR(i, n) {
		FOR(j, m) {
			if (visited[i][j] == 0 && v[i][j]=='L') {
				bfs(i, j);
			}
		}
	}

	cout << ans;

	return 0;
}