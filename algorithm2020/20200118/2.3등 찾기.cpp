#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, string>>v;
	for (int i = 0; i < n; i++) {
		string name;
		int score;
		cin >> name >> score;
		v.push_back(make_pair(score, name));
	}
	sort(v.begin(), v.end());
	cout << v[n - 3].second;
	return 0;
}
