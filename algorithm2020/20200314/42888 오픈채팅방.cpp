#include <bits/stdc++.h>

using namespace std;
vector<string> toToken(string a) {
	char *str_buff = new char[1000];
	strcpy(str_buff, a.c_str());
	string str_arr[3];
	int str_cnt = 0;
	char *tok = strtok(str_buff, " ");
	while (tok != nullptr) {
		str_arr[str_cnt++] = string(tok);
		tok = strtok(nullptr, " ");
	}
	vector<string>res(3);

	for (int i = 0; i < 3; i++)
		res[i] = str_arr[i];
	return res;
}

vector<string> solution(vector<string> record) {
	int sz = record.size();
	vector<vector<string>>v;//문자열 나눈 결과 담은 배열
	map<string, string>mp;
	for (int i = 0; i < sz; i++) {
		v.push_back(toToken(record[i]));
		if (v[i][0] != "Leave")
			mp[v[i][1]] = v[i][2];
	}



	vector<string> answer;
	for (int i = 0; i < sz; i++) {
		string action;
		if (v[i][0] == "Enter") {
			action = "님이 들어왔습니다.";
		}
		else if (v[i][0] == "Change") continue;
		else {
			action = "님이 나갔습니다.";
		}
		auto it = mp.find(v[i][1]);
		string person = it->second;
		string result = person + action;
		answer.push_back(result);
	}



	return answer;
}