class Solution {
public:
	//bruth force
	int checkBalance(string s) {
		int cnt = 0;
		int str_size = s.size();
		if (str_size == 0) return 0;
		//�迭�� ó������ 2���� �߶󰡸鼭 balance���� üũ
		int i;
		for (i = 2; i <= str_size; i += 2) {
			int L = 0, R = 0;
			for (int j = 0; j < i; j++) {
				if (s[j] == 76) L++;
				else R++;
			}
			//L�� R�� ������ ������ �׸�ŭ ����� �ٽ� ��ͷ� balance���� üũ
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