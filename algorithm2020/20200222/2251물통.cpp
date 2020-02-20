#include <bits/stdc++.h>
using namespace std;
struct Node {
	int a;
	int b;
	int c;
};
queue<Node>q;
int visited[200][200][200]; //a,b,c에 간적 있는지
int A, B, C;//각각의 그릇 크기
//give :주는애의 남아있는 양 get:받을애의 남아있는양 
void moveWater(int &give, int &get, int get_bowl) {
	//주는 양+ 현재있는양이 그 그릇의 크기를 초과하면
	if (get + give > get_bowl) {
		give = give - (get_bowl - get);
		get = get_bowl;
	}
	//
	else {
		get += give;
		give = 0;
	}
}
vector<int>ans;
void addAns(int a, int c) {
	if (a == 0) {
		bool exist = false;
		for (auto it = ans.begin(); it != ans.end(); it++) {
			if (*it == c) {
				exist = true; break;
			}
		}
		if (!exist) {
			ans.push_back(c);
		}
	}
}

void bfs() {
	while (!q.empty()) {
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();

		//추가
		addAns(a, c);

		int give;
		int get;
		//C->A
		if (c > 0) {
			give = c;
			get = a;
			moveWater(give, get, A);
			if (visited[get][b][give] == 0) {
				visited[get][b][give] = 1;
				q.push({ get,b,give });
			}

			//C->B
			give = c;
			get = b;
			moveWater(give, get, B);
			if (visited[a][get][give] == 0) {
				visited[a][get][give] = 1;
				q.push({ a,get,give });
			}
		}

		//B->A
		if (b > 0) {
			give = b;
			get = a;
			moveWater(give, get, A);
			if (visited[get][give][c] == 0) {
				visited[get][give][c] = 1;
				q.push({ get,give,c });
			}

			//B->C
			give = b;
			get = c;
			moveWater(give, get, C);
			if (visited[a][give][get] == 0) {
				visited[a][give][get] = 1;
				q.push({ a,give,get });
			}
		}
		//A->B
		if (a > 0) {
			give = a;
			get = b;
			moveWater(give, get, B);
			if (visited[give][get][c] == 0) {
				visited[give][get][c] = 1;
				q.push({ give,get,c });
			}

			//A->C
			give = a;
			get = c;
			moveWater(give, get, C);
			if (visited[give][b][get] == 0) {
				visited[give][b][get] = 1;
				q.push({ give,b,get });
			}
		}

	}
}
int main() {
	cin >> A >> B >> C;
	visited[0][0][C] = 1;
	q.push({ 0, 0, C });
	bfs();
	sort(ans.begin(), ans.end());
	for (auto it = ans.begin(); it != ans.end(); it++) {
		cout << *it << " ";
	}
	return 0;
}