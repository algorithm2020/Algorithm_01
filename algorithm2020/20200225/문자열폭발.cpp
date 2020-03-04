#include <bits/stdc++.h>
using namespace std;

int main() {
	string bomb, in;
	cin >> in >> bomb;
	int in_size = in.size();
	int bomb_size = bomb.size();
	char result[1000001];


	int cnt = 0;
	for (int i = 0; i < in_size; i++) {
		result[cnt++] = in[i];

		if (result[cnt - 1] == bomb[bomb_size - 1]) {
			bool bomb_flag = true; //터질 문자가 있음을 표시

			for (int j = 0; j < bomb_size; j++) {
				if (result[cnt - bomb_size + j] != bomb[j]) {
					bomb_flag = false;
					break;
				}
			}
			if (bomb_flag)cnt -= bomb_size;
		}

	}

	if (cnt != 0) for (int i = 0; i < cnt; i++) {
		cout << result[i];
	}
	else cout << "FRULA";
	return 0;
}