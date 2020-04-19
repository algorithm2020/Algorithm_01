#include <bits/stdc++.h>
using namespace std;
int left_cnt;
int right_cnt;
bool end_flag;
int d[2001][2001]; //왼쪽 idx가 i 오른쪽 idx가 j일때 얻을 수 있는 최대 점수
int visited[2001][2001];
int recur(int left_idx, int right_idx, vector<int>&left, vector<int>&right) {
	if (left_idx == left_cnt || right_idx == right_cnt) {
		return 0;
	}
	if (visited[left_idx][right_idx] != 0) return d[left_idx][right_idx];
	
	for (int i = left_idx; i < left_cnt; i++) {
		for (int j = right_idx; j < right_cnt; j++) {
			if (visited[i][j] == 1) continue;
			visited[left_idx][right_idx] = 1;
			if (left[i] > right[j]) {
				d[i][j] = max(d[i][j], right[j] + recur(i, j + 1, left, right));
			}
			int a = d[i+1][j+1]=recur(i + 1, j + 1, left, right);
			int b = d[i+1][j]=recur(i + 1, j, left, right);
			return d[i][j] = max(d[i][j], max(a, b));
			
		}
	}
}
int solution(vector<int> left, vector<int> right) {
	end_flag = false;
	right_cnt = right.size();
	left_cnt = left.size();
	memset(visited, 0, sizeof(visited));
	memset(d, 0, sizeof(d));
	recur(0, 0, left, right);
	int answer = 0;
	return d[0][0];
}
