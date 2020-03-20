#include <bits/stdc++.h>
using namespace std;
bool check(string a) {
	stack<int>s;
	int sz = a.size();
	for (int i = 0; i < sz; i++) {
		if (a[i] == '(') {
			s.push(1);
		}
		else if (s.empty()) return false;
		else s.pop();
	}
	if (s.empty()) return true;
	else return false;
}
string solution(string p) {
	string answer = "";
	int sz = p.size();
	//1번
	if (sz == 0) return "";

	//2번과정
	string u, v;
	int left = 0, right = 0; // left :(  right: )
	int last = 0;
	for (int i = 0; i < sz; i++) {
		if (p[i] == '(') left++;
		else right++;
		if (left == right) {
			last = i;
			break;
		}
	}
	u = p.substr(0, last + 1);
	v = p.substr(last + 1);

	//3번과정
	if (check(u)) {
		answer = u + solution(v);
	}
	//4번과정
	else {
		string n = "(";
		n = n + solution(v) + ")";
		int u_sz = u.size();
		string tmp = u.substr(1, u_sz - 2);
		int tmp_sz = tmp.size();
		for (int i = 0; i < tmp_sz; i++) {
			if (tmp[i] == '(') tmp[i] = ')';
			else tmp[i] = '(';
		}
		answer = n + tmp;
	}
	return answer;
}