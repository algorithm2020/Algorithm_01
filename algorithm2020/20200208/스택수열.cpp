#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>num(n + 1);
	vector<int>v(n + 1); //수열
	stack<int>s;
	for (int i = 1; i < n + 1; i++) {
		cin >> v[i];
		num[i] = i;
	}
	s.push(0);
	int push_cnt = 1;
	string answer = "";
	for (int i = 1; i <= n; i++) {
		while (1) {
			//vector 원소를 보면서 스택의 탑과 비교한다.
			int top = s.top();

			//스택의탑>vector 원소 =>break and NO
			if (top > v[i]) {
				answer = "NO";
				cout << answer;
				return 0;
			}
			//스택의탑==vector 원소 =>출력해야하는 원소이므로 pop
			else if (top == v[i]) {
				answer += "-\n";
				s.pop();
				break;
			}
			//스택의탑<vector 원소 =>아직 그 숫자에 도달하지 못했으므로 push
			else {
				answer += "+\n";
				s.push(push_cnt++);
			}
		}
	}
	cout << answer;
	return 0;
}