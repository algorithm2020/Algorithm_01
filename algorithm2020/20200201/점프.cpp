#define FOR(x,n) for(int x=0;x<n;x++)
#include<iostream>
#include <cstring>
using namespace std;
int a[100][100]; //�־��� �迭
long long d[100][100]; // d[i][j]=(i,j)���� (n-1,n-1)���� �� �� �ִ� ����� ��
int n;
long long func(int i, int j) {
	//base case
	if (i == n - 1 && j == n - 1) return d[i][j] = 1;
	if (i >= n - 1 && j >= n - 1) return d[i][j]=0;
	int jump = a[i][j];
	d[i][j] = 0;
	//������ ���� ��ȿ�ϸ� �����ϱ�
	//�Ʒ��� ����
	if (i + jump < n) {
		if (d[i + jump][j] == -1)	d[i][j] += func(jump + i, j);
		else d[i][j] += d[i + jump][j];
	}
	//���������� ����
	if (jump + j < n) {
		if (d[i][jump + j] == -1) d[i][j] += func(i, jump + j);
		else d[i][j] += d[i][jump + j];
	}
	return d[i][j];
}
int main() {

	cin >> n;
	FOR(i, n) {
		FOR(j, n) {
			cin >> a[i][j];
		}
	}
	memset(d, -1, sizeof(d));
	cout << func(0, 0);
	return 0;
}