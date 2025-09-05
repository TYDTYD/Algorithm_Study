#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <deque>
using namespace std;

struct Point {
	double x, y;
	Point(double x, double y) : x(x), y(y) {}
	Point(): x(0),y(0) {}
};

Point start = Point();

double cross(Point& a, Point& b, Point& c, Point& d) {
	double result = (b.x - a.x) * (d.y - c.y) - (b.y - a.y) * (d.x - c.x);
	return result;
}

double ccw(Point a, Point b, Point c) {
	double result = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	return result;
}

double distance(Point a, Point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool Compare(Point& a, Point& b) {
	if (ccw(start, a, b) > 0)
		return true;
	else if (ccw(start, a, b) < 0)
		return false;
	return distance(start, a) < distance(start, b);
}

void findSkin(vector<Point>& v, deque<Point>& result) {
	stack<Point> s;
	s.push(v[0]);
	s.push(v[1]);

	for (int i = 2; i < v.size(); i++) {
		while (s.size() >= 2) {
			Point top1 = s.top(); s.pop();
			Point top2 = s.top();
			if (ccw(top2, top1, v[i]) > 0) {
				s.push(top1);
				break;
			}
		}
		s.push(v[i]);
	}
	while (!s.empty()) {
		result.push_back(s.top());
		s.pop();
	}
	result.push_front(result.back());
	result.pop_back();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int p;
	cin >> p;
	while (p--) {
		int n;
		cin >> n;
		vector<Point> points;
		double idxX = 1e9, idxY = -1e9;
		int index = 0;

		for(int i = 0; i < n; i++) {
			double x, y;
			cin >> x >> y;
			if (y > idxY || (y == idxY && x < idxX)) {
				idxY = y;
				idxX = x;
				index = i;
			}				
			Point p(x, y);
			points.push_back(p);
		}

		start = points[index];
		swap(points[0], points[index]);
		sort(points.begin() + 1, points.end(), Compare);

		deque<Point> answer;
		findSkin(points, answer);

		cout << answer.size() << '\n';
		for(const auto& point : answer)
			cout << point.x << ' ' << point.y << '\n';		
	}

	return 0;
}