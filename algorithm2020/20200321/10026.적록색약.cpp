#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
char arr[100][100]; //적록색약 아님 
char arr2[100][100];
int visited[100][100];
int n;
struct Node {
	int x, y;
	char color; //R,G,B;
};
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool isRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}
queue<Node>q;
int ans = 0; //적록색약 x인사람이 보는것
int ans2 = 0; //적록색약인 사람이 보는것
int color[125];
void init() {
	FOR(i, n) {
		FOR(j, n) {
			visited[i][j] = 0;
		}
	}
}
void bfs(int x, int y, char colour, int mode) {
	visited[x][y] = 1;
	q.push({ x,y,colour });
	while (!q.empty()) {
		int xx = q.front().x;
		int yy = q.front().y;
		char ncolor = q.front().color;
		q.pop();
		FOR(i, 4) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (isRange(nx, ny) && visited[nx][ny] == 0) {
				if (mode == 0 && arr[nx][ny] == ncolor) {
					visited[nx][ny] = 1;
					q.push({ nx,ny,ncolor });
				}
				else if (mode == 1 && arr2[nx][ny] == ncolor) {
					visited[nx][ny] = 1;
					q.push({ nx,ny,ncolor });
				}
			}
		}
	}
}
int main() {
	cin >> n;

	FOR(i, n) {
		FOR(j, n) {
			char a;
			cin >> a;
			arr[i][j] = a;
			if (a == 'R' || a == 'G') arr2[i][j] = 'A';
			else arr2[i][j] = a;
		}
	}

	//적록색약 x
	FOR(i, n) {
		FOR(j, n) {
			if (visited[i][j] == 0) {
				bfs(i, j, arr[i][j], 0);
				ans++;
			}
		}
	}

	init();

	//적록색약 x
	FOR(i, n) {
		FOR(j, n) {
			if (visited[i][j] == 0) {
				bfs(i, j, arr2[i][j], 1);
				ans2++;
			}
		}
	}

	cout << ans << " " << ans2;
	return 0;
}