class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		int nums1_size = nums1.size();
		int nums2_size = nums2.size();
		vector<int>a, b, answer;
		a = nums1;
		b = nums2;

		if (nums1_size < nums2_size) {
			a = nums2;
			b = nums1;
			nums1_size = nums2.size();
			nums2_size = nums1.size();
		}
		set<int> s;
		for (int i = 0; i < nums1_size; i++) {
			for (int j = 0; j < nums2_size; j++) {
				if (a[i] == b[j]) s.insert(a[i]);
			}
		}

		set<int>::iterator iter;
		for (iter = s.begin(); iter != s.end(); iter++) {
			answer.push_back(*iter);
		}
		return answer;
	}
};