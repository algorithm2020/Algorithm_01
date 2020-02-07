bool cmp(vector<int>a, vector<int>b) {
	return (abs(a[0] - a[1]) > abs(b[0] - b[1]));
}
class Solution {
public:

	int twoCitySchedCost(vector<vector<int>>& costs) {
		int total_cost = 0;//총 비용
		int cost_size = costs.size();
		sort(costs.begin(), costs.end(), cmp); //costs |(A도시 가는 비용)-(B도시 가는 비용)|이 큰 순으로 정렬


		int n = cost_size / 2; //A도시로 갈 사람 n명, B도시로 갈 사람 n명
		int a = 0, b = 0; //a도시로 가는 경우, b도시로 가는 경우
		for (int i = 0; i < cost_size; i++) {
			int to_a = costs[i][0];
			int to_b = costs[i][1];
			if (to_a <= to_b) {
				if (a < n) { //A도시로 갈 사람 n명을 못 채운경우
					a++;
					total_cost += to_a;
				}
				else { //A도시로 갈 사람 n명을 채운 경우 =>a도시로 가는 cost가 작아도 b도시로 보내기
					b++;
					total_cost += to_b;
				}
			}
			else {
				if (b < n) {//B도시로 갈 사람 n명을 못 채운경우
					b++;
					total_cost += to_b;
				}
				else { //B도시로 갈 사람 n명을 채운 경우 =>B도시로 가는 cost가 작아도 A도시로 보내기
					a++;
					total_cost += to_a;
				}
			}

		}
		return total_cost;
	}
};