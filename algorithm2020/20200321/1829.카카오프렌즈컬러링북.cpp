#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
int mm, nn;
int visited[100][100] = {};
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int number_of_area = 0;
int max_size_of_one_area = 0;
struct Node {
	int x, y, color;
};
bool isRange(int x, int y) {
	return x >= 0 && x < mm && y >= 0 && y < nn;
}
void bfs(int i, int j, int col, vector<vector<int>>&arr) {
	queue<Node>nq;
	nq.push({ i,j,col });
	visited[i][j] = 1;
	int cnt = 0;//영역내 원소개수
	while (!nq.empty()) {
		int x = nq.front().x;
		int y = nq.front().y;
		int color = nq.front().color;
		nq.pop();
		cnt++;
		FOR(i, 4) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isRange(nx, ny) && visited[nx][ny] == 0 && arr[nx][ny] == color) {
				visited[nx][ny] = 1;
				nq.push({ nx,ny,color });
			}
		}
	}
	max_size_of_one_area = max(max_size_of_one_area, cnt);
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	mm = m, nn = n;
	queue<Node>q;
	number_of_area = 0;
	max_size_of_one_area = 0;
	FOR(i, m) {
		FOR(j, n) {
			visited[i][j] = 0;
		}
	}
	FOR(i, m) {
		FOR(j, n) {
			if (picture[i][j] != 0) {
				q.push({ i,j,picture[i][j] });
			}
		}
	}


	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int color = q.front().color;
		if (visited[x][y] == 0) {
			bfs(x, y, color, picture);
			number_of_area++;
		}
		q.pop();
	}
	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}