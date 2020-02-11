#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int l, c;
vector<string>origin;
int checkVow[15];
int visited[15];
void recur(int start, int cnt, int con, int vow) { //con는 자음개수 vow는 모음개수
	if (cnt == l && con >= 2 && vow >= 1) {
		string s;
		for (int i = 0; i < c; i++) {
			if (visited[i] == 1) s += origin[i];
		}
		cout << s << "\n";
		return;
	}

	for (int i = start; i < c; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			if (checkVow[i] == 1) vow++;
			else con++;
			recur(i, cnt + 1, con, vow);
			if (checkVow[i] == 1) 	--vow;
			else --con;

			visited[i] = 0;
		}
	}
}
int main() {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		string s;
		cin >> s;
		origin.push_back(s);
	}

	sort(origin.begin(), origin.end());

	for (int i = 0; i < c; i++) {
		string s = origin[i];
		if (s == "a" || s == "e" || s == "i" || s == "o" || s == "u") {
			checkVow[i] = 1;
		}
	}

	recur(0, 0, 0, 0);
	return 0;
}