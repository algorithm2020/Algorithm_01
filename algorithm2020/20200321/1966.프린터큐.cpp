#define FOR(i,n) for(int i=0;i<n;i++)
#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<char, int>& a, const pair<char, int>& b) {
	return a.second > b.second;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int ans = 0;

		int n, m;

		vector<pair<char, int>>v;
		vector<pair<char, int>>arr; //가장 큰 순서대로 정렬한 것
		vector<char>output;//출력순서
		cin >> n >> m;
		FOR(i, n) {
			int a;
			cin >> a;
			v.push_back({ i,a });
			arr.push_back({ i,a });
		}

		sort(arr.begin(), arr.end(), cmp);
		int idx = 0, i = 0;
		int cnt = n;
		while (cnt > 0) {
			int max_num = arr[idx].second;
			if (i >= n) i = 0;

			if (max_num == v[i].second) {
				output.push_back(v[i].first);
				idx++;
				cnt--;
			}
			i++;
		}

		//출력
		FOR(i, n) {
			if (m == output[i]) {
				cout << i + 1 << "\n";
				break;
			}
		}
	}
	return 0;
}