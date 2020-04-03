#include <bits/stdc++.h>
using namespace std;
int visited[1001][1001];
int sum;
struct node {
	int a, b;
};
queue<node>q;
void check(int a, int b, int c) {
	int arr[3] = { a,b,c };
	if (a == b) return;
	int x = 2 * a;
	int y = b - a;
	if (x == y && x == c) {
		cout << 1;
		exit(0);
	}
	if (x <= 0 || y <= 0) return;
	arr[0] = x;
	arr[1] = y;
	arr[2] = c;
	sort(arr, arr + 3);
	if (visited[arr[0]][arr[1]] == 0) {
		visited[arr[0]][arr[1]] = 1;

		q.push({ arr[0],arr[1] });
	}

}
void bfs() {

	while (!q.empty()) {
		int a = q.front().a;
		int b = q.front().b;
		int c = sum - a - b;
		q.pop();



		check(a, b, c);
		check(a, c, b);
		check(b, a, c);
		check(b, c, a);
		check(c, a, b);
		check(c, b, a);
	}
	cout << 0;
	return;
}
int main() {
	int arr[3];

	cin >> arr[0] >> arr[1] >> arr[2];
	sum = arr[0] + arr[1] + arr[2];

	if (arr[0] == arr[1] && arr[1] == arr[2]) {
		cout << 1;
		return 0;
	}
	else if ((arr[0] + arr[1] + arr[2]) % 3 != 0) {
		cout << 0;
		return 0;
	}

	node Node = { arr[0],arr[1] };
	visited[arr[0]][arr[1]] = 1;
	q.push(Node);

	bfs();
	return 0;
}