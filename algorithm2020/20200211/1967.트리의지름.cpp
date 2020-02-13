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
vector<vector<pair<int, int>>>v(10001); //v[i] first: i->j�� ���� v[i] second �� ����ġ

//��Ʈ��忡�� �ִ��� �հ� 
void dfs(int start, int dist) { //�������� ����Ÿ��� ������ ����
	visited[start] = 1;
	if (max_dist < dist) {
		max_dist = dist;
		max_num = start;
	}
	for (auto it = v[start].begin(); it != v[start].end(); it++) {
		if (visited[it->first] == 0) //�ش������� �湮�� ���� ���� ���
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
	dfs(1, 0); //��Ʈ���� ���� �հ� ���� �湮
	int start = max_num;
	visited.clear();
	visited.resize(n + 1, 0);

	max_num = 0, max_dist = 0;
	dfs(start, 0); //������ ���� ���� �հ�(start)�������� ���� �հ��� ����
	cout << max_dist;
	return 0;
}