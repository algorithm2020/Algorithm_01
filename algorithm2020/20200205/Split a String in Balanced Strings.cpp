class Solution {
public:
	//bruth force
	int checkBalance(string s) {
		int cnt = 0;
		int str_size = s.size();
		if (str_size == 0) return 0;
		//배열의 처음부터 2개씩 잘라가면서 balance인지 체크
		int i;
		for (i = 2; i <= str_size; i += 2) {
			int L = 0, R = 0;
			for (int j = 0; j < i; j++) {
				if (s[j] == 76) L++;
				else R++;
			}
			//L과 R의 개수가 같으면 그만큼 떼어내서 다시 재귀로 balance인지 체크
			if (L == R) {
				cnt++;
				cnt += checkBalance(s.substr(i));
				return cnt;
			}
		}
		return 0;
	}
	int balancedStringSplit(string s) {
		return checkBalance(s);
	}
};