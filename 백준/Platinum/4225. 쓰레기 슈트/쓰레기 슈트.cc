#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <stack>
#include <math.h>
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
	else if (ccw(referencePoint, a, b) < 0)
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

	while (!s.empty()) {
		d.push_front(s.top());
		s.pop();
	}
	return;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed;
	cout.precision(2);
	int n;
	int t = 1;
	while (cin >> n) {
		double answer = 1e9;
		if (n == 0)
			break;

		vector<Point> pos;

		for (int i = 0; i < n; i++) {
			double x, y;
			cin >> x >> y;
			pos.push_back({ x,y });
		}

		referencePoint = pos[0];
		for (int i = 1; i < n; i++) {
			if (pos[i].second < referencePoint.second || 
				(pos[i].second == referencePoint.second && pos[i].first < referencePoint.first)) {
				referencePoint = pos[i];
			}
		}
		sort(pos.begin(), pos.end(), compare);
		deque<Point> convexHull;
		findSkin(pos, convexHull);

		Point dot1, dot2;
		int n = convexHull.size();
		for (int i = 0; i < n; i++) {
			dot1 = convexHull[i];
			dot2 = convexHull[i+1 != n ? i + 1 : 0];
			double result = -1;
			for (int j = 0; j < n; j++) {
				if (j == i || j == i + 1)
					continue;
				double crossResult = cross(dot1, dot2, dot1, convexHull[j]);
				double dotDist = distance(dot1, dot2);
				double dist = crossResult / sqrt(dotDist);
				result = max(result, dist);
			}
			answer = min(answer, result);
		}

		cout << "Case " << t++ << ": " << ceil(answer * 100) / 100 << '\n';
	}

	return 0;
}