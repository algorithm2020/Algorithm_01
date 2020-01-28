#include <iostream>
#include <map>
#include <utility>
#include <string>


using namespace std;
int n, m;

int main() {
	cin.tie(NULL);
	ios::ios_base::sync_with_stdio(false);
	map < string, string > map1; //키 :포켓몬 도감넘버 값:포켓몬 이름
	map < string, string > map2; //키 :포켓몬 이름 값:포켓몬 넘버

	cin >> n>>m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		map1.insert(make_pair(to_string(i + 1), s));
		map2.insert(make_pair(s, to_string(i + 1)));
	}
	
	//m개의 질문
	for (int i = 0; i < m; i++) {
		//주어진 질문의 시작값 확인하여 A~Z이면 map2사용
		string question;
		cin >> question;
		if (question[0] >= 65 && question[0] <= 90) {
			//찾는 값이 없는 경우가 없으므로 예외처리 안해도됨
			cout << map2.find(question)->second << "\n";
		}

		else {
			cout << map1.find(question)->second << "\n";
		}
	}
	return 0;

}