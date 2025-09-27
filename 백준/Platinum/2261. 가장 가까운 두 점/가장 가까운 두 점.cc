#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

struct Point {
	int x, y;
	Point(int x = 0, int y = 0) : x(x), y(y) {}
};

int GetDistance(const Point& p1, const Point& p2) {
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool ComparePoint(const Point& p1, const Point& p2) {
	return p1.y < p2.y;	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<Point> points(n);
	set<pair<int, int>> candidates;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		points[i] = Point(x, y);
	}

	sort(points.begin(), points.end(), ComparePoint);
	candidates.insert({ points[0].x, points[0].y });
	candidates.insert({ points[1].x, points[1].y });
	int d = GetDistance(points[0], points[1]);
	int left = 0;

	for (int i = 2; i < n; i++) {
		double offset = sqrt(d);
		while (left < i) {
			double yDiff = points[i].y - points[left].y;
			if (yDiff > offset) {
				if (candidates.find({ points[left].x, points[left].y }) != candidates.end())
					candidates.erase({ points[left].x, points[left].y });
				left++;
			}
			else
				break;	
		}
		auto lower = candidates.lower_bound({ points[i].x - offset, points[i].y - offset });
		auto upper = candidates.upper_bound({ points[i].x + offset, points[i].y + offset });
		for (auto it = lower; it != upper; it++) {
			auto p = Point(it->first, it->second);
			d = min(d, GetDistance(points[i], p));			
		}
		candidates.insert({ points[i].x, points[i].y });
	}

	cout << d;
	return 0;
}