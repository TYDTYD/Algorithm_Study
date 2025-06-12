#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <stack>
using namespace std;

typedef pair<double, double> Point;

Point start;

double cross(Point a, Point b, Point c, Point d) {
	double result = (b.first - a.first) * (d.second - c.second) - (b.second - a.second) * (d.first - c.first);
	return result;
}

double ccw(Point a, Point b, Point c) {
	double result = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
	return result;
}

double distance(Point a, Point b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

bool compare(Point a, Point b) {
	if (ccw(start, a, b) > 0)
		return true;
	else if (ccw(start, a, b) < 0)
		return false;
	return distance(start, a) < distance(start, b);
}

void findSkin(vector<Point> v, deque<Point>& result) {
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
		result.push_front(s.top());
		s.pop();
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c;
	cin >> c;

	vector<Point> v(c);
	deque<Point> convexHull;
	double mnx = 1e9, mny = 1e9;
	int index = -1;
	for (int i = 0; i < c; i++) {
		double x, y;
		cin >> x >> y;
		if (y < mny) {
			mnx = x;
			mny = y;
			index = i;
		}
		else if (y == mny && x < mnx) {
			mnx = x;
			index = i;
		}
		v[i] = { x, y };
	}

	cout << fixed;
	cout.precision(10);

	if (c == 2) {
		cout << sqrt(distance(v[0], v[1]));
		return 0;
	}

	swap(v[0], v[index]);
	start = v[0];
	sort(v.begin() + 1, v.end(), compare);
	findSkin(v, convexHull);

	double answer = 0;
	int front = 0;
	int back = 1;
	int n = convexHull.size();

	int j = 1;
	for (int i = 0; i < n; i++) {
		int next_i = (i + 1) % n;
		while (cross(convexHull[i], convexHull[next_i], convexHull[j], convexHull[(j+1)%n]) > 0) {
			j = (j + 1) % n;
		}
		answer = max(answer, sqrt(distance(convexHull[i], convexHull[j])));
	}

	cout << answer;

	return 0;
}