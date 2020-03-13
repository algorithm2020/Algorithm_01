#define FOR(i,n,start) for(int i=start;i<n;i++)
#include <bits/stdc++.h>
using namespace std;
int  m, n, k;
int party[50][51];//m번째파티 참석여부
int party_num[50];
int know[51];
int visited[51];
void dfs(int x) {
	visited[x] = 1;
	know[x] = 1;

	FOR(i, m, 0) {
		if (party[i][x] == 0) continue;
		FOR(j, n + 1, 1) {
			if (party[i][j] == 1 && visited[j] == 0 && know[j] == 0) dfs(j);
		}
	}
}
int main() {
	cin >> n >> m >> k;
	//진실 아는 사람
	FOR(i, k, 0) {
		int a;
		cin >> a;
		know[a] = 1;
	}
	//파티 인원 및 명단
	FOR(i, m, 0) {
		cin >> party_num[i];
		FOR(j, party_num[i], 0) {
			int num;
			cin >> num;
			party[i][num] = 1;
		}
	}
	FOR(i, n + 1, 1) {
		if (visited[i] == 0 && know[i] == 1) dfs(i);
	}
	//거짓말 칠수 있는 파티 찾기
	int ans = 0;
	FOR(i, m, 0) {
		int cnt = 0; //특정파티 참석자 수
		FOR(j, n + 1, 1) {
			if (party[i][j] == 1 && know[j] == 1)break;
			else if (party[i][j] == 1) cnt++;
		}
		if (cnt == party_num[i]) ans++;
	}
	cout << ans;
	return 0;
}