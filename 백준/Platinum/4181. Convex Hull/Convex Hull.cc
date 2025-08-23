#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <math.h>
#define INF 1e9
using namespace std;

typedef long long ll;
typedef long double lld;

struct Point {
	ll x, y;
	Point(ll x, ll y) : x(x), y(y) {}
	Point() { x = 0; y = 0; }
};

Point low;

bool distance(Point& p0, Point& p1, Point& p2) {
	double dist1 = ((p2.x - p0.x) * (p2.x - p0.x)) + ((p2.y - p0.y) * (p2.y - p0.y));
	double dist2 = ((p2.x - p1.x) * (p2.x - p1.x)) + ((p2.y - p1.y) * (p2.y - p1.y));
	return dist1 < dist2;
}

ll ccw(Point& a, Point& b, Point& c) {
	ll result = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	return result;
}

bool compare(Point& a, Point& b) {
	if (ccw(low, a, b) == 0)
		return distance(a, b, low);
	return ccw(low, a, b) > 0;
}

void findSkin(vector<Point>& v, deque<Point>& result) {
	stack<Point> s;
	s.push(v[0]);
	s.push(v[1]);

	vector<Point> exception;
	for (int i = 2; i < v.size(); i++) {
		while (s.size() >= 2) {
			Point second = s.top();
			s.pop();
			Point first = s.top();
			if (ccw(first, second, v[i]) >= 0) {
				s.push(second);
				break;
			}
			else
				exception.push_back(second);
		}
		s.push(v[i]);
	}

	while(!exception.empty()) {
		s.push(exception.back());
		exception.pop_back();
	}

	while(!s.empty()) {
		result.push_front(s.top());
		s.pop();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int lowIdx = 0;
	int xIdx, yIdx;
	xIdx = yIdx = INF;
	vector<Point> p;

	for (int i = 0, j = 0; i < n; i++) {
		int x, y;
		char c;
		cin >> x >> y >> c;
		if (c == 'N')
			continue;
		if (xIdx > x || (xIdx == x && yIdx > y)) {
			lowIdx = j;
			xIdx = x;
			yIdx = y;
		}
		p.push_back(Point(x, y));
		j++;
	}

	low = Point(xIdx, yIdx);
	swap(p[0], p[lowIdx]);
	sort(p.begin() + 1, p.end(), compare);
	deque<Point> result;
	findSkin(p, result);
	cout << result.size() << '\n';
	for(auto point : result)
		cout << point.x << ' ' << point.y << '\n';
	return 0;
}