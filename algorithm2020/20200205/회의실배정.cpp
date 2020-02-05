#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

struct meetingtime {
	int begin, end;
};
bool cmp(const meetingtime &x, const meetingtime &y) {
	if (x.end == y.end) {
		return x.begin < y.begin;
	}
	else return x.end < y.end;

}

int main() {
	int n;
	std::cin >> n;

	std::vector<meetingtime> a(n);
	for (int i = 0; i < n; i++) {
		int s, b;
		scanf("%d %d", &s, &b);
		a[i].begin = s;
		a[i].end = b;
	}
	//������ �ð� �������� ����
	sort(a.begin(), a.end(), cmp);

	int now = 0;
	int count = 0;
	//ó������ ������ �󸶳� ���� ȸ�Ǹ� �� �� �ִ���
	for (unsigned int i = 0; i < a.size(); i++) {
		if (now <= a[i].begin) {
			now = a[i].end;
			count += 1;
		}
	}

	std::cout << count;
	return 0;
}