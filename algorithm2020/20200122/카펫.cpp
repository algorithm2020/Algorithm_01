#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	int red_width, red_height;
	for (int i = 1; i <= red; i++) {
		if (red%i == 0) {
			red_width = i;
			red_height = red / i;
			//빨간너비가 높이보다 작으면 제외
			if (red_width < red_height) continue;

			int check = (red_width + 2) * 2 + (red_height * 2);
			if (check == brown) {
				answer.push_back(red_width + 2);
				answer.push_back(red_height + 2);
			}
		}
	}
	return answer;
}