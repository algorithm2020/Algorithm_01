#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	std::ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		bool dependancy = true;
		vector<string> v;
		int n; //전화번호 수
		cin >> n;

		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			v.push_back(s);
		}

		sort(v.begin(), v.end());

		int v_size = v.size();
		for (int i = 1; i < v_size; i++) {
			//이전 스트링이 현재스트링에 포함되면
			if (v[i - 1] == v[i].substr(0, v[i - 1].length())) {
				dependancy = false;
				break;
			}
		}
		if (!dependancy) cout << "NO\n";
		else cout << "YES\n";

	}
	return 0;

}