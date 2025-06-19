#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef pair<double, double> Point;

double GetDistance(Point x, Point y) {
	return sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<Point> points;
	
	double dist = 1e9;

	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		points.push_back({ x,y });
	}

	Point answer = points[0];

	for (int i = 0; i < n; i++) {
		double result = 0;
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			result = max(GetDistance(points[i], points[j]), result);
		}
		if (dist > result) {
			dist = result;
			answer = points[i];
		}
	}

	cout << fixed;
	cout.precision(10);
	cout << answer.first << ' ' << answer.second;
}