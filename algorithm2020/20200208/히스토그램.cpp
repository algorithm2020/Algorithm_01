#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int h[100001]; //높이
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> h[i];
		stack<int>remain;
		h[n] = 0;
		int max_rect = 0;
		for (int i = 0; i < n + 1; i++) {//i는 구하고자 하는 사각형의 오른쪽 index
			while (!remain.empty() && h[remain.top()] >= h[i]) { //empty는 맨처음 인덱스를 넣기위해 필요 
				int j = remain.top(); //구하고자 하는 높이
				remain.pop();
				int width = -1;

				if (remain.empty()) width = i;
				else width = (i - remain.top() - 1); //여기서 remain.top()는 사각형의 왼쪽 index
				max_rect = max(max_rect, h[j] * width);
			}
			remain.push(i); //남아있는 직사각형의 index를 넣어준다
		}
		cout << max_rect;
	}
	return 0;
}