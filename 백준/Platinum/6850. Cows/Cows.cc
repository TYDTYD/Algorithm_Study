#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

double ccw(pair<double, double> x, pair<double, double> y, pair<double,double> z) {
	return (y.first - x.first) * (z.second - x.second) - (y.second - x.second) * (z.first - x.first);
}

double distance(pair<double, double> x, pair<double, double> y) {
	return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);
}

int sortCCW(double result) {
	if (result >= 0)
		return 1;
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<double, double>> points;

	int index = 0;
	int mnX = 1e9;
	int mnY = 1e9;

	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		points.push_back({ x,y });
		if (mnX > x || (mnX == x && mnY > y)) {
			index = i;
			mnX = x;
			mnY = y;
		}
	}

	swap(points[index], points.front());
	auto pivot = points.front();
	sort(points.begin() + 1, points.end(), [pivot](pair<double, double>& x, pair<double, double>& y) {
		double result = ccw(pivot, x, y);
		if (result == 0)
			return distance(pivot, x) < distance(pivot, y);
		return result > 0;
		}
	);

	stack<pair<double, double>> hull;
	hull.push(points[0]);
	hull.push(points[1]);

	for (int i = 2; i < points.size(); i++) {
		while (hull.size() >= 2) {
			auto second = hull.top();
			hull.pop();
			auto first = hull.top();
			if (ccw(first, second, points[i]) > 0) {
				hull.push(second);
				break;
			}
		}
		hull.push(points[i]);
	}
	vector<pair<double, double>> convexHull;

	while (!hull.empty()) {
		convexHull.push_back(hull.top());
		hull.pop();
	}

	double area = 0;
	for (int i = 0; i < convexHull.size(); i++) {
		pair<double,double> x = convexHull[i];
		pair<double,double> y = convexHull[(i + 1) % convexHull.size()];
		area += (x.first * y.second - x.second * y.first);
	}
	area = abs(area) / 2.0;

	cout << floor(area / 50);
	return 0;
}