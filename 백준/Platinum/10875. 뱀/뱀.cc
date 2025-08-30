#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
	long long x, y;
	Point(long long x, long long y) : x(x), y(y) {}
	Point() { x = 0; y = 0; }
};

bool PointSortByX(const Point& a, const Point& b) {
	return a.x < b.x;
}

bool PointSortByY(const Point& a, const Point& b) {
	return a.y < b.y;
}

struct Line {
	Point start, end;
	Line(Point x, Point y) : start(x), end(y) {}
	Line() 
	{
		start = Point();
		end = Point();
	}
};

enum Direction {
	Right, 
	Up, 
	Left, 
	Down
};

bool isOut(long long limit, Point pos, Direction dir) {
	switch (dir)
	{
		case Right:
		if (pos.x > limit)
			return true;
		break;
		case Up:
			if (pos.y > limit)
				return true;
			break;
		case Left:
			if (pos.x < -limit)
				return true;
			break;
		case Down:
			if (pos.y < -limit)
				return true;
			break;
	default:
		break;
	}

	return false;
}

pair<Point, bool> crossCheck(Line a, Line b) {
	if (a.start.x == a.end.x) {
		if(b.start.x == b.end.x) {
			if(a.start.x != b.start.x)
				return { Point(), false };
			else {
				if (min(a.start.y, a.end.y) > max(b.start.y, b.end.y) || min(b.start.y, b.end.y) > max(a.start.y, a.end.y))
					return { Point(), false };
				else {
					if (b.start.y > b.end.y)
						return { Point(a.start.x, max(a.start.y,a.end.y)), true };					
					else
						return { Point(a.start.x, min(a.start.y,a.end.y)), true };					
				}					
			}
		}
		else if (b.start.y == b.end.y) {
			if(b.start.y < min(a.start.y, a.end.y) || b.start.y > max(a.start.y,a.end.y))
				return { Point(), false };
			else if(a.start.x < min(b.start.x, b.end.x) || a.start.x > max(b.start.x, b.end.x))
				return { Point(), false };
			else
				return { Point(a.start.x, b.start.y), true };
		}
	}
	else if (a.start.y == a.end.y) {
		if (b.start.y == b.end.y) {
			if (a.start.y != b.start.y)
				return { Point(), false };
			else {
				if (min(a.start.x, a.end.x) > max(b.start.x, b.end.x) || min(b.start.x, b.end.x) > max(a.start.x, a.end.x))
					return { Point(), false };
				else {
					if(b.start.x > b.end.x)
						return { Point(max(a.start.x, a.end.x), a.start.y), true };
					else
						return { Point(min(a.start.x, a.end.x), a.start.y), true };
				}					
			}
		}
		else if (b.start.x == b.end.x) {
			if (b.start.x < min(a.start.x, a.end.x) || b.start.x > max(a.start.x, a.end.x))
				return { Point(), false };
			else if (a.start.y < min(b.start.y, b.end.y) || a.start.y > max(b.start.y, b.end.y))
				return { Point(), false };
			else
				return { Point(b.end.x, a.start.y), true };
		}
	}
	return { Point(), false };
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<Line> lines;
	long long l;
	cin >> l;
	int n;
	cin >> n;

	long long answer = 0;
	Direction direction = Right;
	Point pos = Point(0, 0);
	bool plag = false;

	for (int i = 0; i <= n; i++) {
		long long t;
		char dir;

		Point start = Point(pos.x, pos.y);
		Point end = Point();
		if (i == n) {
			if (plag)
				continue;
			switch (direction)
			{
			case Right:
				end = Point(l + 1, pos.y);
				pos.x = l + 1;
				break;
			case Up:
				end = Point(pos.x, l + 1);
				pos.y = l + 1;
				break;
			case Left:
				end = Point(-l - 1, pos.y);
				pos.x = -l - 1;
				break;
			case Down:
				end = Point(pos.x, -l - 1);
				pos.y = -l - 1;
				break;
			}
		}
		else {
			cin >> t >> dir;
			if (plag)
				continue;
			switch (direction)
			{
			case Right:
				pos.x += t;
				break;
			case Up:
				pos.y += t;
				break;
			case Left:
				pos.x -= t;
				break;
			case Down:
				pos.y -= t;
				break;
			}
			end = Point(pos.x, pos.y);
			answer += t;
		}

		Line path = Line(start, end);
		bool crossed = false;
		vector<Point> crossPoints;
		for (int j = 0; j < static_cast<int>(lines.size()) - 2; j++) {
			auto result = crossCheck(lines[j], path);
			if (result.second) {
				crossPoints.push_back(result.first);
				crossed = true;
				plag = true;
			}
		}

		if (crossed) {
			Point crossPoint;
			switch (direction)
			{
			case Right:
				sort(crossPoints.begin(), crossPoints.end(), PointSortByX);
				crossPoint = Point(crossPoints.front().x, pos.y);
				break;
			case Up:
				sort(crossPoints.begin(), crossPoints.end(), PointSortByY);
				crossPoint = Point(pos.x, crossPoints.front().y);
				break;
			case Left:
				sort(crossPoints.begin(), crossPoints.end(), PointSortByX);
				crossPoint = Point(crossPoints.back().x, pos.y);
				break;
			case Down:
				sort(crossPoints.begin(), crossPoints.end(), PointSortByY);
				crossPoint = Point(pos.x, crossPoints.back().y);
				break;
			}
			long long offset = abs(crossPoint.x - start.x) + abs(crossPoint.y - start.y);
			if (i == n)
				answer += offset;
			else
				answer -= (t - offset);
			continue;
		}
		if (i == n) {
			answer += abs(pos.x - start.x) + abs(pos.y - start.y);
			continue;
		}
		if (isOut(l, pos, direction)) {
			plag = true;
			if (pos.x > l)
				answer -= (pos.x - l - 1);
			else if (pos.x < -l)
				answer += (pos.x + l + 1);
			else if (pos.y > l)
				answer -= (pos.y - l - 1);
			else
				answer += (pos.y + l + 1);
			continue;
		}

		lines.push_back(path);
		if (dir == 'L')
			direction = static_cast<Direction>((direction + 1) % 4);
		else
			direction = static_cast<Direction>((direction + 3) % 4);
	}

	cout << answer;
	return 0;
}