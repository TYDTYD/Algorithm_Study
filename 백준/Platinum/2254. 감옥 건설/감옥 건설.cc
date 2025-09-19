#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

struct Point{
	long long x, y;
};

long long distance(Point p1, Point p2) {
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int ccw(Point p1, Point p2, Point p3) {
	long long val = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
	if (val > 0) return 1;
	if (val < 0) return -1;
	return 0;
}

pair<vector<Point>, bool> findSkin(vector<Point>& v, Point& prison) {
	stack<Point> s;
	s.push(v[0]);
	s.push(v[1]);
	int delNum = 1;
	vector<int> delIdx;
	stack<int> remainIdx;
	remainIdx.push(0);
	remainIdx.push(1);

	for (int i = 2; i < v.size(); i++) {		
		while (s.size() >= 2) {
			Point top1 = s.top(); s.pop();
			Point top2 = s.top();
			if (ccw(top2, top1, v[i]) > 0) {
				delNum = i;
				remainIdx.push(delNum);				
				s.push(top1);				
				break;
			}
			else {
				delIdx.push_back(delNum);
				if (!remainIdx.empty()) {
					remainIdx.pop();
					if (!remainIdx.empty())
						delNum = remainIdx.top();
				}
			}
		}
		s.push(v[i]);
	}

	if (s.size() <= 2) {
		return { {}, false };
	}
	else {
		bool isInside = true;
		while (s.size() >= 2) {
			Point top1 = s.top(); s.pop();
			Point top2 = s.top();
			if (ccw(top2, top1, prison) <= 0) {
				isInside = false;
				break;
			}
		}
		if (!isInside)
			return { {}, false };
	}

	vector<Point> remainPoints;
	for (const auto& idx : delIdx)
		remainPoints.push_back(v[idx]);
	return { remainPoints, true };
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, px, py;
	cin >> n >> px >> py;
	vector<Point> points(n);	
	Point prison = { px, py };

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		points[i] = { x, y };
	}

	int answer = 0;
	while (!points.empty()) {
		int idx = 0;
		int size = points.size();
		long long x = 1e9, y = 1e9;
		for (int i = 0; i < size; i++) {
			if (points[i].x < x || (x == points[i].x && points[i].y < y)) {
				x = points[i].x;
				y = points[i].y;
				idx = i;
			}		
		}

		swap(points[0], points[idx]);
		sort(points.begin() + 1, points.end(), [&](Point p1, Point p2) {
			int val = ccw(points[0], p1, p2);
			if (val == 0)
				return distance(points[0], p1) < distance(points[0], p2);
			return val > 0;
			});
		
		auto result = findSkin(points, prison);
		if (!result.second)
			break;			

		answer++;
		points = result.first;
	}
	
	cout << answer;
	return 0;
}