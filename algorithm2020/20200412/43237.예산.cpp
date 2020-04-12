/*
�̺�Ž��
start=0���� �ϴ°� ����Ʈ
start,end ���� ���� -1,+1�ؾ� while�� ���� <-����!
*/
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> budgets, int M) {
	int answer = 0;
	sort(budgets.begin(), budgets.end());
	int sz = budgets.size();
	long long budget_sum = 0;
	//�״�� �����ϴ°��
	for (int i = 0; i < sz; i++) {
		budget_sum += budgets[i];
	}
	if (budget_sum <= M) {
		return budgets[sz - 1];
	}

	//���Ѿ� ���ϱ�

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