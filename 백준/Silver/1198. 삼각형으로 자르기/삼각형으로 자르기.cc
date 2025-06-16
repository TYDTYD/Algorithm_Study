#include <iostream>
#include <deque>
using namespace std;

typedef pair<double, double> point;

double cross(point& a, point& b, point& c) {
	point p1 = { c.first - a.first, c.second - a.second };
	point p2 = { c.first - b.first, c.second - b.second };
	return p1.first * p2.second - p1.second * p2.first;
}

int main() {
	int n;
	cin >> n;
	deque<point> points;
	double answer = 0;

	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		points.push_front({ x,y });
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				answer = max(cross(points[i], points[j], points[k]), answer);
			}
		}
	}

	cout << fixed;
	cout.precision(10);
	cout << answer * 0.5;

	return 0;
}