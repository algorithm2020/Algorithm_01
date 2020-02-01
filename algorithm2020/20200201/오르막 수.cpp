#include <iostream>
using namespace std;
int d[1001][10] = { {0,0,0,0,0,0,0,0,0,0} ,{1,1,1,1,1,1,1,1,1,1} };
int answer[1001] = { 0,10 };
int main() {
	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++)
			{
				d[i][j] += d[i - 1][k] % 10007;
			}
			answer[i] += d[i][j] % 10007;
			answer[i] %= 10007;
		}

	}
	cout << answer[n];
	return 0;
}