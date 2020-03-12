#include <bits/stdc++.h>
using namespace std;
int n;
int visited[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
vector<int>route;
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		
		visited[x][y] = 1;
		//시작점
		route.clear();
		route.push_back(d);
		x += dx[d], y += dy[d];
		visited[x][y] = 1;
		for (int i = 0; i < g; i++) { //세대 만들기
			int size_ = route.size();
			for (int j = size_-1; j >=0; j--) {
				int new_dir = (route[j] + 1) % 4;
				route.push_back(new_dir);
				x += dx[new_dir], y += dy[new_dir];
				visited[x][y] = 1;
			}	
		}
	}

	//정사각형 체크
	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (visited[i][j] == 1 && visited[i + 1][j] == 1 && visited[i][j + 1] == 1 && visited[i + 1][j + 1] == 1) ans++;
		}
	}
	cout << ans;
	return 0;
}