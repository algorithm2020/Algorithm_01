#include <iostream>
using namespace std;
int Arr[12] = { 0,1,2,4 };

int getAdd(int n) {
	if (Arr[n] != 0) return Arr[n];

	else return Arr[n] = getAdd(n - 1) + getAdd(n - 2) + getAdd(n - 3);
}
int main() {
	int n, m;
	cin >> n;

	while (n--) {
		cin >> m;
		cout << getAdd(m) << endl;
	}
	return 0;
}