#include <iostream>
#include <vector>
using namespace std;

struct Point {
	double x, y;	
};

struct Line {
	Point start, end;
};

struct Rectangle {
	Point topLeft, bottomRight, topRight, bottomLeft;
};

double ccw(Point a, Point b, Point c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool crossCheck(Line a, Line b) {
	double d1 = ccw(a.start, a.end, b.start);
	double d2 = ccw(a.start, a.end, b.end);
	double d3 = ccw(b.start, b.end, a.start);
	double d4 = ccw(b.start, b.end, a.end);
	double d5 = ccw(a.end, a.start, b.start);
	double d6 = ccw(a.end, a.start, b.end);
	double d7 = ccw(b.end, b.start, a.start);
	double d8 = ccw(b.end, b.start, a.end);

	double result1 = d1 * d2;
	double result2 = d3 * d4;
	double result3 = d5 * d6;
	double result4 = d7 * d8;

	if(result1 == 0 && result2 == 0 && result3 == 0 && result4 == 0) {
		if(a.start.x > a.end.x)
			swap(a.start, a.end);
		else if(a.start.x == a.end.x && a.start.y > a.end.y)
			swap(a.start, a.end);
		if (b.start.x > b.end.x)
			swap(b.start, b.end);
		else if (b.start.x == b.end.x && b.start.y > b.end.y)
			swap(b.start, b.end);
		if((a.start.x <= b.end.x && a.end.x >= b.start.x) && (a.start.y <= b.end.y && a.end.y >= b.start.y))
			return true;		
		return false;
	}

	if(result1 <= 0 && result2 <= 0 && result3 <= 0 && result4 <= 0)
		return true;	
	return false;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		vector<Point> points(4);
		Line line;
		for (int i = 0; i < 4; i++)
			cin >> points[i].x >> points[i].y;		

		line.start = points[0];
		line.end = points[1];

		double minX = min(points[2].x, points[3].x);
		double minY = min(points[2].y, points[3].y);
		double maxX = max(points[2].x, points[3].x);
		double maxY = max(points[2].y, points[3].y);		

		Rectangle rect;
		rect.bottomLeft = { minX, minY };
		rect.topRight = { maxX, maxY };
		rect.topLeft = { minX, maxY };
		rect.bottomRight = { maxX, minY };

		Line rectLines[4];
		rectLines[0] = { rect.topLeft, rect.topRight };
		rectLines[1] = { rect.topRight, rect.bottomRight };
		rectLines[2] = { rect.bottomRight, rect.bottomLeft };
		rectLines[3] = { rect.bottomLeft, rect.topLeft };
		
		bool isCross = false;

		if (line.start.x >= minX && line.start.y >= minY && line.start.x <= maxX && line.start.y <= maxY
			&& line.end.x >= minX && line.end.y >= minY && line.end.x <= maxX && line.end.y <= maxY) {
			cout << "T\n";
			continue;
		}

		for (int i = 0; i < 4; i++) {
			if(crossCheck(line, rectLines[i])) {
				isCross = true;
				break;
			}
		}

		if(isCross)
			cout << "T\n";
		else
			cout << "F\n";
	}

	return 0;
}