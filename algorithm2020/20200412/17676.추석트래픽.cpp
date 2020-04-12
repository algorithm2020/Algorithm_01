#include <bits/stdc++.h>
using namespace std;
int solution(vector<string> lines) {
	int answer = 0;
	vector<pair<int, int>>v;
	int sz = lines.size();
	for (int i = 0; i < sz; i++) {
		int h = stoi(lines[i].substr(11, 2)) * 3600000;
		int m = stoi(lines[i].substr(14, 2)) * 60000;
		int s = stoi(lines[i].substr(17, 2)) * 1000;
		int ss = stoi(lines[i].substr(20, 3));
		int end = h + m + s + ss;
		int t_s = stoi(lines[i].substr(24, 1)) * 1000;
		int t;
		if (lines[i].size() < 27) {
			t = t_s;
		}
		else {
			int t_ss = stoi(lines[i].substr(26, lines[i].size() - 2));
			t = t_s + t_ss;
		}

		int start = end - t + 1;
		v.push_back({ start,end });
	}

	//종료시간 기준으로
	for (int i = 0; i < sz; i++) {
		int cnt = 0;
		int end_t = v[i].second + 999;

		for (int j = i; j <sz; j++) {
			if (v[j].first <= end_t) cnt++;
			else if (v[j].second >= v[i].second) cnt++;
		}
		answer = max(answer, cnt);
	}

	return answer;
}