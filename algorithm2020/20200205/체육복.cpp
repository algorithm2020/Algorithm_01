#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> deleteVector(vector<int>v) {
	for (auto it = v.begin(); it != v.end();) {
		if (*it == 0) it = v.erase(it);
		else it++;
	}
	return v;
}
int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	answer = n - lost.size();
	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());
	bool it_end = false;
	int lost_size = lost.size();
	int reserve_size = reserve.size();
	//여벌 체육복이 있으나, 자기 체육복 없는 사람 미리 제거
	for (int i = 0; i < lost_size; i++) {
		for (int j = 0; j < reserve_size; j++) {
			if (lost[i] == reserve[j] && lost[i] != 0 && reserve[j] != 0) {
				lost[i] = 0;
				reserve[j] = 0;
				answer++;
				break;
			}
		}
	}
	lost = deleteVector(lost);
	reserve = deleteVector(reserve);
	for (auto it = lost.begin(); it != lost.end(); it++) {
		for (auto it2 = reserve.begin(); it2 != reserve.end(); it2++) {
			if (*it == *it2 + 1 || *it == *it2 - 1) {
				answer++;
				reserve.erase(it2);
				break;
			}
		}
	}
	return answer;
}