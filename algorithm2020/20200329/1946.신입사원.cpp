#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
int n;
vector<pair<int, int>>v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		v.clear();
		FOR(i, n) {
			int a, b;
			cin >> a >> b;
			v.push_back({ a,b });
		}

		sort(v.begin(), v.end());

		int cnt = 0;
		int high_interview = 100001;
		FOR(i, n) {
			if (high_interview > v[i].second) {
				high_interview = v[i].second;
				cnt++;
			}

		}
		cout << cnt << "\n";
	}
	return 0;

}