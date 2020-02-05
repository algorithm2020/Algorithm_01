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
	//끝나는 시간 기준으로 정렬
	sort(a.begin(), a.end(), cmp);

	int now = 0;
	int count = 0;
	//처음부터 끝까지 얼마나 많은 회의를 할 수 있는지
	for (unsigned int i = 0; i < a.size(); i++) {
		if (now <= a[i].begin) {
			now = a[i].end;
			count += 1;
		}
	}

	std::cout << count;
	return 0;
}