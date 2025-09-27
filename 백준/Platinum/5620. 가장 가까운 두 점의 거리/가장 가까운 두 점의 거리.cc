#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

typedef pair<int, int> Point;

int GetDistance(const Point& x, const Point& y) {
	return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<Point> points;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		points.push_back({ x,y });
	}
	sort(points.begin(), points.end(), [](const auto& p1, const auto& p2) {
		return p1.second < p2.second;
		}
	);
	set<Point> candidatePoints;
	candidatePoints.insert(points[0]);
	candidatePoints.insert(points[1]);

	int index = 0;
	int d = GetDistance(points[0], points[1]);

	for (int i = 2; i < n; i++) {
		Point now = points[i];
		double dist = sqrt(d);
		while (index < i) {
			double offset = now.second - points[index].second;
			if (offset > dist) {
				if (candidatePoints.find(points[index]) != candidatePoints.end())
					candidatePoints.erase(points[index]);
				index++;
			}
			else
				break;
		}
		auto lower = candidatePoints.lower_bound(Point(now.first - sqrt(d), now.second - sqrt(d)));
		auto upper = candidatePoints.upper_bound(Point(now.first + sqrt(d), now.second + sqrt(d)));
		for(auto it = lower; it != upper; it++)
			d = min(d, GetDistance(now, *it));
		candidatePoints.insert(now);
	}

	cout << d;
	return 0;
}