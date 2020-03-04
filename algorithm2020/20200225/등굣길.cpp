#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int d[101][101]; //(i,j)�� �� �� �ִ� ����� ��
int mm, nn;
bool isRange(int x, int y) {
	return x > 0 && x <= nn && y > 0 && y <= mm && d[x][y] != -1;
}
void init() {
	for (int i = 1; i <= nn; i++) {
		for (int j = 1; j <= mm; j++) {
			if (i == 1 || j == 1)
				d[i][j] = 1;
			else d[i][j] = 0; //�ʱ�ȭ
		}
	}
}
int recur(int x, int y) {

	//�湮�ߴ� ���̸� �״�� ����
	if (d[x][y] != 0) return d[x][y];

	if (isRange(x - 1, y)) d[x][y] += recur(x - 1, y);
	if (isRange(x, y - 1))d[x][y] += recur(x, y - 1);
	return d[x][y] = d[x][y] % 1000000007;
}
int solution(int m, int n, vector<vector<int>> puddles) {
	mm = m, nn = n;
	init();
	for (int i = 0; i < puddles.size(); i++) {
		d[puddles[i][1]][puddles[i][0]] = -1;
		if (puddles[i][1] == 1) { //x��ǥ�� 1�� ���� ��� ������ �ǹ̰�����
			for (int j = puddles[i][0]; j <= m; j++) {
				d[1][j] = -1;
			}
		}
		if (puddles[i][0] == 1) { //y��ǥ�� 1�� ���� ��� ������ �ǹ̰�����
			for (int j = puddles[i][1]; j <= n; j++) {
				d[j][1] = -1;
			}
		}
	}
	return recur(n, m);
}