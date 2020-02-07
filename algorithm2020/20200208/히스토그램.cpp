#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int h[100001]; //����
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> h[i];
		stack<int>remain;
		h[n] = 0;
		int max_rect = 0;
		for (int i = 0; i < n + 1; i++) {//i�� ���ϰ��� �ϴ� �簢���� ������ index
			while (!remain.empty() && h[remain.top()] >= h[i]) { //empty�� ��ó�� �ε����� �ֱ����� �ʿ� 
				int j = remain.top(); //���ϰ��� �ϴ� ����
				remain.pop();
				int width = -1;

				if (remain.empty()) width = i;
				else width = (i - remain.top() - 1); //���⼭ remain.top()�� �簢���� ���� index
				max_rect = max(max_rect, h[j] * width);
			}
			remain.push(i); //�����ִ� ���簢���� index�� �־��ش�
		}
		cout << max_rect;
	}
	return 0;
}