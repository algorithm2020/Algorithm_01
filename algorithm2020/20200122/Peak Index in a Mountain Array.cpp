class Solution {
public:
	int peakIndexInMountainArray(vector<int>& A) {
		int maxIndex = 10001;
		int maxNum = -1;
		int A_size = A.size();
		for (int i = 0; i < A_size; i++) {
			if (A[i] > maxNum) {
				maxNum = A[i];
				maxIndex = i;
			}
		}
		return maxIndex;
	}
};