#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
long long n;
vector<long long>v;
vector<vector<long long>>ans(100);
map<long long, long long>mp;
long long visited[100];
vector<long long> recur(long long start) {
	auto idx = mp.find(start);
	if (visited[idx->second] == 1)return ans[idx->second];
	visited[idx->second] = 1;
	vector<long long>res;
	res.push_back(start);
	if (start % 3 == 0 && find(v.begin(), v.end(), start / 3) != v.end()) {
		vector<long long> res2 = recur(start / 3);
		res.insert(res.end(), res2.begin(), res2.end());
	}

	else if (find(v.begin(), v.end(), start * 2) != v.end()) {
		vector<long long>res2 = recur(start * 2);
		res.insert(res.end(), res2.begin(), res2.end());
	}
	ans[idx->second] = res;

	if (ans[idx->second].size() == n) {
		FOR(i, n) {
			cout << ans[idx->second][i] << " ";
		}
		exit(0);
	}
	return res;
}
int main() {
	cin >> n;
	FOR(i, n) {
		long long a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end(), greater<long long>());
	FOR(i, n) {
		mp[v[i]] = i;
	}
	FOR(i, n) {
		if (visited[i] == 0) recur(v[i]);
	}
	return 0;

}