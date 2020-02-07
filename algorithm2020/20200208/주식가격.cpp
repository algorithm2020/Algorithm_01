#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
	int n = prices.size();
	vector<int> answer(n, 0);
	for (int i = 0; i < n - 1; i++) {
		int cnt = 1;
		if (prices[i] > prices[i + 1]) {
			answer[i] = 1;
			continue;
		}
		for (int j = i + 2; j < n; j++) {
			cnt++;
			if (prices[i] > prices[j]) break;

		}
		answer[i] = cnt;
	}
	return answer;
}