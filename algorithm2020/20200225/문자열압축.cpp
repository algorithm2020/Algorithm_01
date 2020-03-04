#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 1001;
	int cnt = 1;
	int len = s.size();
	for (int j = 1; j < len; j++) {
		string ss = s.substr(0, j);
		string ans = "";
		int i;
		for (i = j; i < len; i += j) {
			string cmp = s.substr(i, j);
			if (ss == cmp) cnt++;
			else {
				if (cnt != 1) {
					ans += to_string(cnt);
				}
				ans += ss;
				ss = cmp;
				cnt = 1;
			}
			//마지막에 다 하기
			if (i >= len - j) {
				if (cnt != 1) {
					ans += to_string(cnt);
				}
				ans += ss;
				cnt = 1;
			}
		}
		answer = min(answer, (int)ans.size());
	}
	if (answer == 1001) answer = 1;
	return answer;
}