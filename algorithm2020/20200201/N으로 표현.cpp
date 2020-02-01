#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX_NUM 1000000
using namespace std;
int answer[MAX_NUM];

int min_(int a,int b) {
	if (a == -2) return b;
	else if (b == -2) return a;

	if (a >= b) return a;
	else return b;
}
void init() {
	for (int i = 0; i < MAX_NUM; i++) {
		answer[i] = -2;
	}
}
int dfs(int N, int number, int origin, int count,int possible) {
	//한번도 그 숫자에 도달한 적이 없는데 카운트가 8이상이면 무시
	if (count >= 8 && answer[origin]==-2) {
		answer[origin] = -1;
		return 0;
	}
	answer[origin] = min_(count,answer[origin]);
	//base case
	if (origin == number) {
		return answer[origin];
	}
	//이어붙이기
	int tmp = origin * 10 + N;

	if (tmp < MAX_NUM&& answer[tmp] == -2 && possible == 0) {
		dfs(N, number, tmp, count + 1, 0);
	}
	//곱하기
	if (origin * N < MAX_NUM && answer[origin * N] == -2) {
		dfs(N, number, origin*N, count + 1, 1);
	}
	//더하기
	if (origin + N < MAX_NUM && answer[origin + N] == -2) {
		dfs(N, number, origin + N, count + 1, 1);
	}
	//나누기
	if (origin / N < MAX_NUM && answer[origin / N] == -2) {
		dfs(N, number, origin / N, count + 1,1);
	}
	return answer[number];
}
int solution(int N, int number) {
	init();
	answer[N] = 1;
	dfs(N, number, N, 0, 0);
	return answer[number];
}
int main() {
	solution(5, 12);
	return 0;
}