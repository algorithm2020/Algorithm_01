struct Point {
	int x;
	int y;
};
class Solution {
public:
	int getDist(Point pt) {
		return pt.x*pt.x + pt.y*pt.y;
	}
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		map<int, vector<Point>>map;
		vector<vector<int>>answer(K);
		int v_size = points.size();
		for (int i = 0; i < v_size; i++) {
			Point point;
			point.x = points[i][0];
			point.y = points[i][1];
			int dist = getDist(point);
			map[dist].push_back(point);

		}
		int i = 0;
		for (auto iter = map.begin(); i < K; ++iter) {
			int v_size = iter->second.size();
			for (int j = 0; j < v_size; j++) {
				int x = iter->second[j].x;
				int y = iter->second[j].y;
				answer[i].push_back(x);
				answer[i].push_back(y);
				++i;
			}
		}
		return answer;
	}
};