class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		multiset<int>s;
		//multiset에 넣기 (중복허용)
		for (auto it = stones.begin(); it != stones.end(); it++) {
			s.insert(*it);
		}
		//가장 큰 두 수를 비교한 값을 새로 넣기
		//가장 큰 두 수 제거
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