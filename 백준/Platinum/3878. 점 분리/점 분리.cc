#include <iostream>
#include <vector>
#include <array>
#include <math.h>
#include <algorithm>
#include <deque>
#include <stack>
using namespace std;

struct Point {
	double x, y;
	Point(double x, double y) : x(x), y(y) {}
};

Point start(0,0);

double cross(Point a, Point b, Point c, Point d) {
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

bool isInside(deque<Point>& skin, vector<Point>& points) {
	if (skin.empty())
		return false;
	for (int i = 0; i < points.size(); i++) {
		Point p = points[i];
		int crossCount = 0;
		for (int j = 0; j < skin.size(); j++) {
			Point a = skin[j];
			Point b = skin[(j + 1) % skin.size()];
			if (a.y > b.y)
				swap(a, b);
			if (ccw(a, p, b) == 0) {
				if (min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y))
					return true;
			}
			if (p.x > max(a.x, b.x))
				continue;
			if (p.y <= a.y)
				continue;
			if (p.y > b.y)
				continue;
			if (p.x < min(a.x, b.x))
				crossCount++;
			else if (ccw(a, p, b) < 0)
				crossCount++;
		}
		if (crossCount % 2 != 0)
			return true;
	}
	return false;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	while (T--) {
		int n, m;
		cin >> n >> m;

		vector<Point> white, black;
		double mnx = 1e9, mny = 1e9;
		int index = -1;
		for (int i = 0; i < n; i++) {
			double x, y;
			cin >> x >> y;
			if (y < mny || (y == mny && x < mnx)) {
				mnx = x;
				mny = y;
				index = i;
			}
			black.push_back({ x, y });
		}
		swap(black[0], black[index]);
		start = black[0];
		sort(black.begin() + 1, black.end(), compare);
		
		mnx = 1e9, mny = 1e9;
		index = -1;
		for (int i = 0; i < m; i++) {
			double x, y;
			cin >> x >> y;
			if (y < mny || (y == mny && x < mnx)) {
				mnx = x;
				mny = y;
				index = i;
			}
			white.push_back({ x, y });
		}
		
		swap(white[0], white[index]);
		start = white[0];
		sort(white.begin() + 1, white.end(), compare);		

		if (n == 1 && m == 1) {
			cout << "YES" << '\n';
			continue;
		}
		if (n == 2 && m == 2) {
			if (ccw(black[0], black[1], white[0]) == 0 && ccw(black[0], black[1], white[1]) == 0 &&
				ccw(white[0], white[1], black[0]) == 0 && ccw(white[0], white[1], black[1]) == 0) {
				if(min(black[0].x, black[1].x) <= max(white[0].x, white[1].x) &&
					max(black[0].x, black[1].x) >= min(white[0].x, white[1].x) &&
					min(black[0].y, black[1].y) <= max(white[0].y, white[1].y) &&
					max(black[0].y, black[1].y) >= min(white[0].y, white[1].y)) {
					cout << "NO" << '\n';
				}
				else if(min(white[0].x, white[1].x) <= max(black[0].x, black[1].x) &&
					max(white[0].x, white[1].x) >= min(black[0].x, black[1].x) &&
					min(white[0].y, white[1].y) <= max(black[0].y, black[1].y) &&
					max(white[0].y, white[1].y) >= min(black[0].y, black[1].y)) {
					cout << "NO" << '\n';
				}
				else {
					cout << "YES" << '\n';
				}
			}				
			else if (ccw(black[0], black[1], white[0]) * ccw(black[0], black[1], white[1]) <= 0 ||
				ccw(white[0], white[1], black[0]) * ccw(white[0], white[1], black[1]) <= 0) {
				cout << "NO" << '\n';
			}
			else {
				cout << "YES" << '\n';
			}
			continue;
		}

		bool isWhite = false;
		deque<Point> whiteSkin, blackSkin;
		if (n > 1)
			findSkin(black, blackSkin);
		if (m > 1)
			findSkin(white, whiteSkin);		

		bool isWhiteInsideBlack = isInside(blackSkin, white);
		bool isBlackInsideWhite = isInside(whiteSkin, black);

		
		if (n == 1 && m > 1) {
			if (isBlackInsideWhite)
				cout << "NO" << '\n';
			else
				cout << "YES" << '\n';
			continue;
		}
		if (m == 1 && n > 1) {
			if (isWhiteInsideBlack)
				cout << "NO" << '\n';
			else
				cout << "YES" << '\n';
			continue;
		}

		if(!isWhiteInsideBlack && !isBlackInsideWhite)
			cout << "YES" << '\n';		
		else
			cout << "NO" << '\n';
	}

	return 0;
}