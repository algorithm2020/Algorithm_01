#include <bits/stdc++.h>
using namespace std;
struct Node {
	string genre;
	int play, eigen;

};
bool cmp(const pair<int, int>&a, const pair<int, int>&b) {
	return a.first > b.first;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	int n = genres.size();

	vector<pair<string, pair<int, int>>>v; //�帣,�÷���Ƚ��,������ȣ
	vector<pair<int, int>>inner; //�� ���Ƚ��,������ȣ

	for (int i = 0; i < n; i++) {
		v.push_back({ genres[i],{plays[i],-i } });
	}
	sort(v.begin(), v.end());

	int cnt = v[0].second.first;
	for (int i = 1; i < n; i++) {
		if (v[i].first != v[i - 1].first) {
			inner.push_back({ cnt,i - 1 });
			cnt = v[i].second.first;
		}
		else {
			cnt += v[i].second.first;
		}
	}
	if (cnt != 0) inner.push_back({ cnt,n - 1 });

	//�帣���� ���� ���� ���Ƚ��ã��
	sort(inner.begin(), inner.end(), cmp);
	for (auto it = inner.begin(); it != inner.end(); it++) {
		int i = it->second;
		answer.push_back(-v[i].second.second);

		if (i != 0 && v[i].first == v[i - 1].first)
		{
			answer.push_back(-v[i - 1].second.second);
		}
	}
	return answer;
}