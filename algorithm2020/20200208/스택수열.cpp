#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>num(n + 1);
	vector<int>v(n + 1); //����
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
			//vector ���Ҹ� ���鼭 ������ ž�� ���Ѵ�.
			int top = s.top();

			//������ž>vector ���� =>break and NO
			if (top > v[i]) {
				answer = "NO";
				cout << answer;
				return 0;
			}
			//������ž==vector ���� =>����ؾ��ϴ� �����̹Ƿ� pop
			else if (top == v[i]) {
				answer += "-\n";
				s.pop();
				break;
			}
			//������ž<vector ���� =>���� �� ���ڿ� �������� �������Ƿ� push
			else {
				answer += "+\n";
				s.push(push_cnt++);
			}
		}
	}
	cout << answer;
	return 0;
}