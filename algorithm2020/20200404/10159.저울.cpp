#include <bits/stdc++.h>
#define FOR(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n, m;
int v[101][101];
//v[i][j] i>j 이면 1 i<j 이면 -1 아직모르면 0
int main() {
	cin >> n >> m;
	FOR(i, m) {
		int a, b;
		cin >> a >> b;
		v[a][b] = 1;
		v[b][a] = -1;
	}


	FOR(k, n) {
		FOR(i, n) {
			FOR(j, n) {
				if (v[i][k] == 1 && v[k][j] == 1 && v[i][j] == 0) {
					v[i][j] = 1;
					v[j][i] = -1;
				}
				if (v[i][k] == -1 && v[k][j] == -1 && v[i][j] == 0) {
					v[i][j] = -1;
					v[j][i] = 1;
				}
			}
		}
	}
	//result
	FOR(i, n) {
		int cnt = 0;
		FOR(j, n) {
			if (v[i][j] == 0)cnt++;
		}
		cout << cnt - 1 << "\n";
	}
	return 0;
}