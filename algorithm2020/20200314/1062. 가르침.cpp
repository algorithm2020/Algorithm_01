#include <bits/stdc++.h>
using namespace std;
int n, k;
string s[50];
int visited[26];
int ans = 0;
void dfs(int start, int cnt) {
	if (cnt == k - 5) {
		//기존 단어들과 비교
		int num = 0;
		for (int i = 0; i < n; i++) {
			bool end_flag = false;
			int sz = s[i].size();
			for (int j = 0; j < sz; j++) {
				if (visited[s[i][j] - 97] == 0) {
					end_flag = true;
					break;
				}
			}
			if (!end_flag)num++;
		}
		ans = max(ans, num);
		return;
	}

	for (int i = start; i < 26; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			dfs(i, cnt + 1);
			visited[i] = 0;
		}
	}
}
void init() {
	visited['a' - 97] = 2;
	visited['n' - 97] = 2;
	visited['i' - 97] = 2;
	visited['t' - 97] = 2;
	visited['c' - 97] = 2;
}
int main() {
	cin >> n >> k;

	init(); //a,c,i,t,n 제외
	if (k < 5) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	dfs(0, 0);
	cout << ans;
	return 0;
}