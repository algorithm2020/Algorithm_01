bool cmp(vector<int>a, vector<int>b) {
	return (abs(a[0] - a[1]) > abs(b[0] - b[1]));
}
class Solution {
public:

	int twoCitySchedCost(vector<vector<int>>& costs) {
		int total_cost = 0;//�� ���
		int cost_size = costs.size();
		sort(costs.begin(), costs.end(), cmp); //costs |(A���� ���� ���)-(B���� ���� ���)|�� ū ������ ����


		int n = cost_size / 2; //A���÷� �� ��� n��, B���÷� �� ��� n��
		int a = 0, b = 0; //a���÷� ���� ���, b���÷� ���� ���
		for (int i = 0; i < cost_size; i++) {
			int to_a = costs[i][0];
			int to_b = costs[i][1];
			if (to_a <= to_b) {
				if (a < n) { //A���÷� �� ��� n���� �� ä����
					a++;
					total_cost += to_a;
				}
				else { //A���÷� �� ��� n���� ä�� ��� =>a���÷� ���� cost�� �۾Ƶ� b���÷� ������
					b++;
					total_cost += to_b;
				}
			}
			else {
				if (b < n) {//B���÷� �� ��� n���� �� ä����
					b++;
					total_cost += to_b;
				}
				else { //B���÷� �� ��� n���� ä�� ��� =>B���÷� ���� cost�� �۾Ƶ� A���÷� ������
					a++;
					total_cost += to_a;
				}
			}

		}
		return total_cost;
	}
};