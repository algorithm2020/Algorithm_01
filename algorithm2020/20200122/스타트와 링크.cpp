#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int s[20][20];
int visited[20];
int minCap = 10000;
int people;
int *arr = new int[people];

int sumScore(vector<int> v) {
	int sum = 0;
	for (int i = 0; i < people / 2; i++) {
		for (int j = i + 1; j < people / 2; j++) {
			sum += s[v[i]][v[j]];
			sum += s[v[j]][v[i]];
		}
	}
	return sum;
}

int min(int a, int b) {
	return a > b ? b : a;
}
void recur(int n, int cnt) {
	//n/2�����ϸ� �³׵��� �ձ��ϱ�
	if (cnt == people / 2) {
		vector<int>start;
		vector<int>link;
		for (int i = 0; i < people; i++) {
			//��ŸƮ�� ��� ����
			if (visited[i] == 1) {
				start.push_back(i);
			}
			//��ũ�� ����
			else {
				link.push_back(i);
			}

		}
		//�� ����Ͽ� ������Ʈ
		int start_score = sumScore(start);
		int link_score = sumScore(link);
		int cap = abs(start_score - link_score);
		minCap = min(minCap, cap);
		return;
	}

	for (int i = n; i < people; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			recur(i, cnt + 1);
			visited[i] = 0;
		}
	}
	return;
}
int main() {
	cin >> people;

	for (int i = 0; i < people; i++) {
		for (int j = 0; j < people; j++) {
			cin >> s[i][j];
		}
	}
	recur(0, 0);
	cout << minCap;
	delete[] arr;
	return 0;
}