#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, leaf = 0;
vector<vector<int>>v(50);
int visited[50];
int del[50];//1이면 삭제되었다는 뜻
void dfs(int x) {
	del[x] = 1;
	visited[x] = 1;
	int size_ = v[x].size();

	for (int i = 0; i < size_; i++) {
		int new_x = v[x][i];
		//루트 노드이면
		if (new_x == -1) continue;
		if (visited[new_x] == 0) {
			del[new_x] = 1;
			dfs(new_x);
			visited[new_x] = 0;
		}
	}
}
int main() {
	cin >> n;
	//원소가 없으면 루트
	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		if (s >= 0) {
			v[s].push_back(i);
		}
		//루트 노드이면
		/*else {
			v[i].push_back(s);
		}*/
	}
	int nn;
	while (cin >> nn) {
		if (visited[nn] == 0)dfs(nn);
	}

	for (int i = 0; i < n; i++) {
		if (del[i] == 0) {
			//원래 연결된 갯수
			int del_cnt = v[i].size();
			//원래부터 자식이 없었으면
			if (del_cnt == 0) {
				leaf++;
				continue;
			}
			for (auto it = v[i].begin(); it != v[i].end(); it++) {
				if (del[*it] == 1) del_cnt--; //삭제당한거 개수 세기
			}

			if (del_cnt == 0) leaf++;
		}
	}
	cout << leaf;
	return 0;
}