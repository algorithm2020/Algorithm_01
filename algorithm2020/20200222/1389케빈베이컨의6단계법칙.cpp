#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>v(101,vector<int>(101));//연결여부
vector<vector<int>>v2(101, vector<int>(101));//케빈베이컨수
int n, m;
int visited[101];
int min_v[101];//케빈베이컨수 합친것
struct Node {
	int x, cnt;
};
queue<Node>q;
void bfs(int ii) {
	q.push({ ii,0 }); //케빈 베이컨 기준이 되는 수
	int visited[101] = {};//무한루프 방지용 방문
	while (!q.empty()) {
		int x = q.front().x;
		int cnt = q.front().cnt;
		visited[x] = 1;
		q.pop();
		for (int i = 1; i <= n;i++) {
			if (v[x][i] == 0 || visited[i]==1) continue; //연결 안되어있으면 통과
			visited[i] = 1;
			v2[ii][i] = min(v2[ii][i], cnt + 1);
			q.push({ i,cnt + 1 });
		}
	}
	for (int i = 1; i <= n; i++) {
		if(ii!=i)
		min_v[ii] += v2[ii][i];
	}
}
void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			v2[i][j] = 7;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a][b]	= 1;
		v[b][a] = 1;
	}
	init();
	for (int i = 1; i <= n; i++) {
		bfs(i);
	}
	int min_num=10000; //제일 적은 베이컨수
	int ans = 1;//제일 작은 베이컨수를 가진 사람 번호
	for (int i = 1; i <= n; i++) {
		if (min_num > min_v[i]) {
			min_num = min_v[i];
			ans = i;
		}
	}
	cout << ans;
	return 0;
}