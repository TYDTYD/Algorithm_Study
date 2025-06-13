#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
#include <deque>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Point;

Point referencePoint;

ll cross(Point a, Point b, Point c, Point d) {
	return (b.first - a.first) * (d.second - c.second) - (b.second - a.second) * (d.first - c.first);
}

ll ccw(Point a, Point b, Point c) {
	return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}

ll distance(Point a, Point b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

bool compare(Point a, Point b) {
	if (ccw(referencePoint, a, b) > 0)
		return true;
	else if(ccw(referencePoint, a, b) < 0)
		return false;
	return distance(referencePoint, a) < distance(referencePoint, b);
}

void findSkin(vector<Point> p, deque<Point>& d) {
	stack<Point> s;
	s.push(p[0]);
	s.push(p[1]);

	int n = p.size();

	for (int i = 2; i < n; i++) {
		while (s.size() >= 2) {
			Point top1 = s.top();
			s.pop();
			Point top2 = s.top();
			if (ccw(top2, top1, p[i]) > 0) {
				s.push(top1);
				break;
			}
		}
		s.push(p[i]);
	}

	while(!s.empty()) {
		d.push_front(s.top());
		s.pop();
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		pair<Point, Point> answer;
		vector<Point> points(n);
		ll mnX = 1e9, mnY = 1e9;
		int index = -1;

		for (int i = 0; i < n; i++) {
			ll x, y;
			cin >> x >> y;
			points[i] = { x, y };
			if (x < mnX || (x == mnX && y < mnY)) {
				mnX = x;
				mnY = y;
				index = i;
			}
		}

		if (n == 2) {
			cout << points[0].first << ' ' << points[0].second << ' ' << points[1].first << ' ' << points[1].second << '\n';
			continue;
		}

		swap(points[0], points[index]);
		referencePoint = points[0];
		sort(points.begin() + 1, points.end(), compare);
		deque<Point> convexHull;
		findSkin(points, convexHull);

		int size = convexHull.size();
		Point zero = { 0,0 };
		int front = 0;
		int back = 0;

		for (int i = 0; i < size; i++) {
			if (convexHull[i].first < convexHull[front].first)
				front = i;
			else if (convexHull[i].first > convexHull[back].first)
				back = i;
		}

		ll maxDistance = distance(convexHull[front], convexHull[back]);
		answer = { convexHull[front], convexHull[back] };

		for (int i = 0; i < size; i++) {
			while (back + 1 != front && cross(convexHull[front], convexHull[(front + 1) % size], convexHull[back], convexHull[(back + 1) % size]) > 0) {
				back = (back + 1) % size;
			}
			if (maxDistance < distance(convexHull[front], convexHull[back])) {
				maxDistance = distance(convexHull[front], convexHull[back]);
				answer = { convexHull[front], convexHull[back] };
			}
			front = (front + 1) % size;
		}

		cout << answer.first.first << ' ' << answer.first.second << ' ' << answer.second.first << ' ' << answer.second.second << '\n';
	}
	return 0;
}