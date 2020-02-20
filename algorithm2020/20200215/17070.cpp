#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
int n;
vector<vector<int>>arr(16);
int visited[16][16]; //


struct Node {
	pair<int, int>tail;
	pair<int, int>head;
};
//가로로 갈수있니?
bool isRange1(int i,int j) {
	return (j + 1 < n) && arr[i][j + 1] == 0;
}
//세로로 가기
bool isRange2(int i, int j) {
	return i + 1 < n && arr[i + 1][j] == 0;
}
//대각선으로 가기
bool isRange3(int i, int j) {
	return (i + 1 < n) && (j + 1 < n) && arr[i + 1][j] == 0 && arr[i][j + 1] == 0 && arr[i + 1][j + 1] == 0;
}
int val = 0;
int dfs(Node node, int dir) {

	int x1 = node.head.first;
	int y1 = node.head.second;
	visited[x1][y1] = 1;
	if (x1== n - 1 && y1== n - 1) {
		val++;
		return 0;
	}
	
	
	switch (dir)
	{
		//가로
	case 0:
		//가로로 가기
		if (visited[x1][y1+1] == 0 && isRange1(x1, y1)) {
			dfs({{ x1,y1 }, { x1,y1+1 }},0 );
			visited[x1][y1 + 1] = 0;
		}
		//대각으로 가기
		if (visited[x1 + 1][y1 + 1] == 0 && isRange3(x1, y1)) {
			dfs({{ x1,y1 }, { x1 + 1,y1+1 }},2);
			visited[x1 + 1][y1 + 1] = 0;
		}
		break;
		//세로
	case 1:
		//세로로 가기
		if (visited[x1+1][y1] == 0 && isRange2(x1, y1)) {
			dfs({ { x1,y1 }, { x1+1,y1} }, 1);
			visited[x1 + 1][y1] = 0;
		}
		//대각으로 가기
		if (visited[x1 + 1][y1 + 1] == 0 && isRange3(x1, y1)) {
			dfs({ { x1,y1 }, { x1 + 1,y1+1 } }, 2);
			visited[x1 + 1][y1 + 1] = 0;
		}
		break;
		//대각
	case 2:
		//가로로 가기
		if (visited[x1][y1+1] == 0 && isRange1(x1, y1)) {
			dfs({ { x1,y1 }, { x1,y1+1 } }, 0);
			visited[x1][y1 + 1] = 0;
		}
		//세로로 가기
		if (visited[x1+1][y1] == 0 && isRange2(x1, y1)) {
			dfs( {{ x1,y1 }, { x1+1,y1}},1);
			visited[x1 + 1][y1] = 0;
		}
		//대각으로 가기
		if (visited[x1 + 1][y1 + 1] == 0 && isRange3(x1, y1)) {
			dfs({ { x1,y1 }, { x1 + 1,y1 +1} }, 2);
			visited[x1 + 1][y1 + 1] = 0;
		}
		break;
	default:
		break;
	}

	if (val)return val;
	else return 0;
}



queue<pair<Node, int>>q;
bool bfs() {
	while (!q.empty()) {
		int x1 = q.front().first.head.first;
		int y1 = q.front().first.head.second;
		int dir = q.front().second;
		q.pop();

		if (x1 == n - 1 && y1 == n - 1) {
			return true;
		}
		switch (dir)
		{
			//가로
		case 0:
			//가로로 가기
			if (visited[x1 + 1][y1] == 0 && isRange1(x1, y1)) {
				visited[x1 + 1][y1] = 1;
				q.push({ {{ x1,y1 }, { x1 + 1,y1 }},0 });
				visited[x1 + 1][y1] = 0;
			}
			//대각으로 가기
			if (visited[x1 + 1][y1 + 1] == 0 && isRange3(x1, y1)) {
				visited[x1 + 1][y1 + 1] = 1;
				q.push({ {{ x1,y1 }, { x1 + 1,y1 }},0 });
			}
				break;
			//세로
		case 1:
			//세로로 가기
			if (visited[x1][y1+1] == 0 && isRange2(x1, y1)) {
				visited[x1][y1 + 1] = 1;
				q.push({ {{ x1,y1 }, { x1,y1+1 }},0 });
			}
			//대각으로 가기
			if (visited[x1 + 1][y1 + 1] == 0 && isRange3(x1, y1)) {
				visited[x1 + 1][y1 + 1] = 1;
				q.push({ {{ x1,y1 }, { x1 + 1,y1+1 }},0 });
			}
			break;
			//대각
		case 2:
			//가로로 가기
			if (visited[x1 + 1][y1] == 0 && isRange1(x1, y1)) {
				visited[x1 + 1][y1] = 1;
				q.push({ {{ x1,y1 }, { x1 + 1,y1 }},0 });
			}
			//세로로 가기
			if (visited[x1][y1 + 1] == 0 && isRange2(x1, y1)) {
				visited[x1][y1 + 1] = 1;
				q.push({ {{ x1,y1 }, { x1,y1 + 1 }},0 });
			}
			//대각으로 가기
			if (visited[x1 + 1][y1 + 1] == 0 && isRange3(x1, y1)) {
				visited[x1 + 1][y1 + 1] = 1;
				q.push({ {{ x1,y1 }, { x1 + 1,y1 + 1 }},0 });
			}
			break;
		default:
			break;
		}
	}
}
void init() {
	FOR(i, n) {
		FOR(j, n) {
			visited[i][j] = 0;
		}
	}
	visited[0][0] = 1, visited[0][1] = 1;
}

int main() {
	cin >> n;
	FOR(i, n) {
		FOR(j, n) {
			int a;
			cin >> a;
			arr[i].push_back(a);
		}
	}
	int cnt = 0;
	init();
	cnt+=dfs({ { 0,0 }, { 0, 1 } }, 0);


	cout << cnt;
	return 0;
}
