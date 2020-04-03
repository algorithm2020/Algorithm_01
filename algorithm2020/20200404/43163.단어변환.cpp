#include <bits/stdc++.h>

using namespace std;
string g_target;
int ans = 100;
int sz;
int wd_sz;
bool end_flag = false;
void recur(string begin, int visited[], vector<string>words, int cnt) {

	if (begin == g_target) { //같을 경우
		int cnt = 0;
		for (int i = 0; i < wd_sz; i++) {
			if (visited[i] != 0)cnt++;
		}
		ans = min(ans, cnt);
		end_flag = true;
		return;
	}

	for (int i = 0; i < wd_sz; i++) {
		int cnt2 = 0;
		for (int j = 0; j < sz; j++) {
			if (begin[j] != words[i][j]) cnt2++;
			if (cnt2 > 1) break;
		}
		if (cnt2 == 1 && visited[i] == 0) {
			visited[i] = cnt;
			recur(words[i], visited, words, cnt + 1);
			visited[i] = 0;
		}
	}
}
int solution(string begin, string target, vector<string> words) {
	g_target = target;
	sz = begin.size();
	wd_sz = words.size();
	int visited[50] = {};
	recur(begin, visited, words, 1);

	for (int i = 0; i < wd_sz; i++) {
		//begin에서 visited[i]>0인 곳으로 바로 갈 수 있으면

	}


	return end_flag == true ? ans : 0;
}