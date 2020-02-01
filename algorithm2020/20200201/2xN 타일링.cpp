#include <iostream>
using namespace std;
int d[1001];
int main() {
	d[1] = 1;
	d[2] = 2;
	int n;
	cin >> n;
	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 1] + d[i - 2]) % 10007;
	}
	cout << d[n];
	return 0;
}