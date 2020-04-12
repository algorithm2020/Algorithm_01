/*
이분탐색
start=0으로 하는게 포인트
start,end 값을 각각 -1,+1해야 while이 종료 <-주의!
*/
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> budgets, int M) {
	int answer = 0;
	sort(budgets.begin(), budgets.end());
	int sz = budgets.size();
	long long budget_sum = 0;
	//그대로 배정하는경우
	for (int i = 0; i < sz; i++) {
		budget_sum += budgets[i];
	}
	if (budget_sum <= M) {
		return budgets[sz - 1];
	}

	//상한액 정하기

    long long start = 0, end = budgets[sz-1], mid = (start + end) / 2;
	
	while (start<=end) {
		int sum = 0;
		for (int i = 0; i < sz; i++) {
			if (budgets[i] <= mid) sum += budgets[i];
			else sum += mid;
		}
		if (sum > M) {
			end = mid-1;
			mid = (start + end) / 2;
		}
        else if(sum==M) {
            return mid;
        }
		else {
			start = mid+1;
			mid = (start + end) / 2;
		}
	}
	return mid;
}