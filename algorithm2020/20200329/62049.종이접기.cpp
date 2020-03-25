#include <string>
#include <vector>
#define FOR(i,n) for(int i=1;i<n;i++)
using namespace std;

vector<int> solution(int n) {
	vector<int> answer;
	answer.push_back(0);

	FOR(i, n) {
		int m = answer.size();
		vector<int>res = answer;
		res.push_back(0);
		for (int j = m - 1; j >= 0; j--) {
			if (answer[j] == 0)res.push_back(1);
			else res.push_back(0);
		}
		answer = res;
	}
	return answer;
}