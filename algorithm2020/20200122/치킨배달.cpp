#include <iostream>
#include <cmath>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstring>
#define FOR(x,n) for(int x=0;x<n;x++)
using namespace std;

int arr[50][50];
int n;
int m;
vector<pair<int, int>>chicken;
vector<pair<int, int>>house;
vector<vector<int>>dist(13, vector<int>(100)); //열이 집, 행이 치킨집

int min_city_distance = 10000000;
int house_count = 0;
int chicken_count = 0;
int visited[13];
int min(int a, int b) {
	return a > b ? b : a;
}

void recur(int start, int cnt) {
	if (cnt == m) {
		//m개 치킨집에 대해 모든 집에서 치킨 거리 구하기
		int house_dists = 0;
		for (int i = 0; i < house_count; i++) {
			int min_dist = 1000000;
			for (int j = 0; j < chicken_count; j++) {
				if (visited[j] == 1) {
					min_dist = min(dist[j][i], min_dist);
				}
			}
			house_dists += min_dist;
		}
		min_city_distance = min(min_city_distance, house_dists);
		return;
	}

	//치킨집 m개 선택
	for (int i = start; i < chicken_count; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			recur(i, cnt + 1);
			visited[i] = 0;
		}
	}
}
int main() {
	cin >> n;
	cin >> m;
	FOR(i, n) {
		FOR(j, n) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				house.push_back(make_pair(i + 1, j + 1));
				house_count++;
			}
			else if (arr[i][j] == 2) {
				chicken.push_back(make_pair(i + 1, j + 1));
				chicken_count++;
			}
		}
	}

	//모든 집에 대해 
	for (int i = 0; i < house_count; i++) {
		//모든 치킨집까지의 치킨거리를 구하고 최소값을 저장
		for (int j = 0; j < chicken_count; j++) {
			int distance = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
			dist[j][i] = distance;
		}

	}
	memset(visited, 0, sizeof(visited));
	recur(0, 0);
	cout << min_city_distance;
	return 0;
}