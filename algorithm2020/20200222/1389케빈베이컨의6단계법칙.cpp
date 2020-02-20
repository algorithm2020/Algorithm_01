#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>v(101,vector<int>(101));//���Ῡ��
vector<vector<int>>v2(101, vector<int>(101));//�ɺ�������
int n, m;
int visited[101];
int min_v[101];//�ɺ������� ��ģ��
struct Node {
	int x, cnt;
};
queue<Node>q;
void bfs(int ii) {
	q.push({ ii,0 }); //�ɺ� ������ ������ �Ǵ� ��
	int visited[101] = {};//���ѷ��� ������ �湮
	while (!q.empty()) {
		int x = q.front().x;
		int cnt = q.front().cnt;
		visited[x] = 1;
		q.pop();
		for (int i = 1; i <= n;i++) {
			if (v[x][i] == 0 || visited[i]==1) continue; //���� �ȵǾ������� ���
			visited[i] = 1;
			v2[ii][i] = min(v2[ii][i], cnt + 1);
			q.push({ i,cnt + 1 });
		}
	}
	for (int i = 1; i <= n; i++) {
		if(ii!=i)
		min_v[ii] += v2[ii][i];
	}
}
void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			v2[i][j] = 7;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a][b]	= 1;
		v[b][a] = 1;
	}
	init();
	for (int i = 1; i <= n; i++) {
		bfs(i);
	}
	int min_num=10000; //���� ���� ��������
	int ans = 1;//���� ���� ���������� ���� ��� ��ȣ
	for (int i = 1; i <= n; i++) {
		if (min_num > min_v[i]) {
			min_num = min_v[i];
			ans = i;
		}
	}
	cout << ans;
	return 0;
}