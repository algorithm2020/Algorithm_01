class Solution {
public:
	int minDeletionSize(vector<string>& A) {
		int str_cnt = A.size();
		int str_size = A[0].size();
		int cnt = 0;//DÀÇ °³¼ö
		for (int i = 0; i < str_size; i++) {
			for (int j = 0; j < str_cnt - 1; j++) {
				if (A[j][i] > A[j + 1][i]) {
					cnt++;
					break;
				}
			}
		}
		return cnt;
	}
};