#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	vector<int>a, b;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int aa;
		cin >> aa;
		a.push_back(aa);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int aa;
		cin >> aa;
		b.push_back(aa);
	}
	vector<int>v(m, 0);

	sort(a.begin(), a.end());

	int b_size = b.size();
	int start, end, center;
	for (int i = 0; i < b_size; i++) {
		start = 0;
		end = n - 1;
		center = (start + end) / 2;
		while (start <= end) {
			if (b[i] > a[center]) {
				start = center + 1;
				center = (start + end) / 2;
			}
			else if (b[i] == a[center]) {
				v[i] = 1;
				break;
			}
			else {
				end = center - 1;
				center = (start + end) / 2;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		cout << v[i] << " ";
	}
	return 0;
}