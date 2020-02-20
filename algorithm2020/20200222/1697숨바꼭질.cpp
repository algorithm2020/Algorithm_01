#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n, k, count;
int minnum = 100000;
int visited[100001] = { 0 };


queue<int>q;

int bfs(int x) {
	q.push(x);

	visited[x] = 1;

	while (!q.empty()) {
		int p = q.front();
		q.pop();

		if (p == k) return visited[p] - 1;

		if (p - 1 >= 0 && visited[p - 1] == 0) {
			visited[p - 1] = visited[p] + 1;
			q.push(p - 1);
		}
		if (p + 1 <= 100000 && visited[p + 1] == 0) {
			visited[p + 1] = visited[p] + 1;
			q.push(p + 1);
		}
		if (2 * p <= 100000 && visited[2 * p] == 0) {
			visited[2 * p] = visited[p] + 1;
			q.push(2 * p);
		}
	}
}

int main() {
	cin >> n >> k;

	cout << bfs(n);
	return 0;
}