#include<bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
int tetroX[19][4] = {
	{0,0,0,0}, // - - - -
{0,1,2,3},

{0,0,1,1},	//- -
			//- -

{0,0,0,-1},//- -
{0,0,0,-1},//  -
{0,0,0,1},//   -
{0,0,0,1},
{0,0,1,2},
{0,0,1,2},
{0,1,2,2},
{0,1,2,2},

{0,0,0,1},//  -
{0,1,2,1},//- - -
{0,1,1,2},
{0,-1,0,0},

{0,1,1,2},	//-
{0,1,1,2},	//--
{0,0,-1,-1},// -
{0,0,-1,-1}
};

int tetroY[19][4] = {
	{0,1,2,3}, // - - - -
{0,0,0,0},

{0,1,0,1},	//- -
						//- -

{0,1,2,2},	//- -
{0,-1,-2,-2},//	-
{0,1,2,0},	//	-
{0,-1,-2,0},
{0,1,1,1},
{0,-1,-1,-1},
{0,0,0,1},
{0,0,0,-1},

{0,1,2,1},	//	-
{0,0,0,1},	//- - -
{0,-1,0,0},
{0,1,1,2},

{0,0,1,1},
{0,0,-1,-1},
{0,1,1,2},
{0,-1,-1,-2}
};
int n, m;
int arr[500][500];
int ans = 0;
bool isRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}
void Solve(int x, int y) {
	bool end_flag = false;

	FOR(i, 19) {
		int val = 0;
		FOR(j, 4) {
			int nx = x + tetroX[i][j];
			int ny = y + tetroY[i][j];
			if (!isRange(nx, ny)) {
				end_flag = true;
				break;
			}
			val += arr[nx][ny];
		}
		if (end_flag) val = 0;
		ans = max(ans, val);
		end_flag = false;
	}
}
int main() {
	cin >> n >> m;
	FOR(i, n) {
		FOR(j, m) {
			cin >> arr[i][j];
		}
	}
	FOR(i, n) {
		FOR(j, m) {
			Solve(i, j);
		}
	}
	cout << ans;
	return 0;
}