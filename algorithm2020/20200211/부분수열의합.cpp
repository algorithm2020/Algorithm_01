#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, s;
vector<int>v(20);
int visited[20];
int answer = 0;
void recur(int start, int sum, int cnt, int target_cnt) {
	if (cnt == target_cnt && sum == s) {
		answer++;
		return;
	}

	//다음꺼 방문
	for (int i = start; i < n; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			sum += v[i]; //합해서 다음꺼로 가기
			recur(i, sum, cnt + 1, target_cnt);
			sum -= v[i];
			visited[i] = 0;
		}
	}

}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		recur(0, 0, 0, i + 1);
	}
	cout << answer;
	return 0;
}