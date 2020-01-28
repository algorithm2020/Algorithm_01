#include <iostream>
#include <map>
#include <utility>
#include <string>


using namespace std;
int n, m;

int main() {
	cin.tie(NULL);
	ios::ios_base::sync_with_stdio(false);
	map < string, string > map1; //Ű :���ϸ� �����ѹ� ��:���ϸ� �̸�
	map < string, string > map2; //Ű :���ϸ� �̸� ��:���ϸ� �ѹ�

	cin >> n>>m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		map1.insert(make_pair(to_string(i + 1), s));
		map2.insert(make_pair(s, to_string(i + 1)));
	}
	
	//m���� ����
	for (int i = 0; i < m; i++) {
		//�־��� ������ ���۰� Ȯ���Ͽ� A~Z�̸� map2���
		string question;
		cin >> question;
		if (question[0] >= 65 && question[0] <= 90) {
			//ã�� ���� ���� ��찡 �����Ƿ� ����ó�� ���ص���
			cout << map2.find(question)->second << "\n";
		}

		else {
			cout << map1.find(question)->second << "\n";
		}
	}
	return 0;

}