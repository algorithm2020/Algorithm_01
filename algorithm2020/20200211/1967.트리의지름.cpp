#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
#include <cstring>
#include <utility>
#define FOR(i,n) for(int i=0;i<n-1;i++)
using namespace std;
int n;
vector<int> visited(10001, 0);
int max_num = 0;
int max_dist = 0;
vector<vector<pair<int, int>>>v(10001); //v[i] first: i->j로 갈때 v[i] second 가 가중치

//루트노드에서 최대한 먼곳 
void dfs(int start, int dist) { //시작점과 현재거리를 가지고 있음
	visited[start] = 1;
	if (max_dist < dist) {
		max_dist = dist;
		max_num = start;
	}
	for (auto it = v[start].begin(); it != v[start].end(); it++) {
		if (visited[it->first] == 0) //해당지점을 방문한 적이 없을 경우
		{
			dfs(it->first, dist + it->second);
		}
	}

}
int main() {
	cin >> n;
	FOR(i, n) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b ,c });
		v[b].push_back({ a,c });
	}
	dfs(1, 0); //루트에서 가장 먼곳 먼저 방문
	int start = max_num;
	visited.clear();
	visited.resize(n + 1, 0);

	max_num = 0, max_dist = 0;
	dfs(start, 0); //위에서 구한 가장 먼곳(start)에서부터 가장 먼곳을 구함
	cout << max_dist;
	return 0;
}