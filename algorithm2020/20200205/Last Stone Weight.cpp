class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		multiset<int>s;
		//multiset�� �ֱ� (�ߺ����)
		for (auto it = stones.begin(); it != stones.end(); it++) {
			s.insert(*it);
		}
		//���� ū �� ���� ���� ���� ���� �ֱ�
		//���� ū �� �� ����
		for (auto it = s.rbegin(); it != s.rend();) {
			int first = *it;
			auto ij = it;
			ij++;
			s.erase(ij.base());
			if (it == s.rend()) return first;
			int second = *it;
			ij = it;
			ij++;
			s.erase(ij.base());
			s.insert(abs(first - second));
		}
		return 0;
	}
};