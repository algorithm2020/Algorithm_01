#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, k, s;
vector<vector<int>>v(401);
int visited[401][401];

bool end_flag = false;
queue<int>q;
void bfs(int start) { //start->end로 가는것이 있는지
	q.push({ start });
	int num_visit[401] = {}; //초기화를 해야 다시 갈 수 있음
	num_visit[start] = 1;
	while (!q.empty()) {
		int s = q.front();
		q.pop();

		for (auto it = v[s].begin(); it != v[s].end(); it++) {
			if (num_visit[*it] == 0) {
				num_visit[*it] = 1;
				visited[start][*it] = 1;
				q.push(*it);
			}
		}
	}
}

int main() {
	cin >> n >> k;
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < k; i++) {
		int s1, s2;
		cin >> s1 >> s2;
		v[s1].push_back(s2);
	}

	for (int i = 1; i <= n; i++) {
		bfs(i);
	}

	cin >> s;
	for (int i = 0; i < s; i++) {
		int s1, s2;
		cin >> s1 >> s2;
		if (visited[s1][s2] == 1) cout << -1 << "\n";
		else if (visited[s2][s1] == 1) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
	return 0;
}