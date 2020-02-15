#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
int n, m;
vector<vector<int>>v(2000);
int visited[2000];
bool ans = false;
void dfs(int start, int cnt) {
	visited[start] = 1;
	if (cnt == 5) {
		ans = true;
		return;
	}
	for (auto it = v[start].begin(); it != v[start].end(); it++) {
		if (visited[*it] == 0) {
			visited[*it] = 1;
			dfs(*it, cnt + 1);
			visited[*it] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	FOR(i, m) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}
	FOR(i, n) {
		memset(visited, 0, sizeof(visited));
		dfs(i, 1);
		if (ans) break;
	}
	if (ans) cout << 1;
	else cout << 0;
	return 0;
}