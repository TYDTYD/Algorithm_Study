#include <iostream>
using namespace std;

struct Line {
	double x1, y1, x2, y2;
	Line(double _x1, double _y1, double _x2, double _y2)
		:x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}

	
};

struct Vector {
	double x, y;
	void makeVector(double x1, double y1, double x2, double y2) {
		x = x2 - x1;
		y = y2 - y1;
	}
};

struct Cross {
	double value;

	void makeCross(Vector v1, Vector v2) {
		value = v1.x * v2.y - v2.x * v1.y;
	}
};

int main() {
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	Line l1 = Line(x1, y1, x2, y2);
	cin >> x1 >> y1 >> x2 >> y2;
	Line l2 = Line(x1, y1, x2, y2);

	Vector v1;
	v1.makeVector(l1.x1, l1.y1, l1.x2, l1.y2);

	Vector v2;
	v2.makeVector(l1.x1, l1.y1, l2.x1, l2.y1);

	Vector v3;
	v3.makeVector(l1.x1, l1.y1, l2.x2, l2.y2);

	Vector v4;
	v4.makeVector(l2.x1, l2.y1, l2.x2, l2.y2);

	Vector v5;
	v5.makeVector(l2.x1, l2.y1, l1.x1, l1.y1);

	Vector v6;
	v6.makeVector(l2.x1, l2.y1, l1.x2, l1.y2);

	Cross c1;
	Cross c2;
	Cross c3;
	Cross c4;

	c1.makeCross(v1, v2);
	c2.makeCross(v1, v3);

	c3.makeCross(v4, v5);
	c4.makeCross(v4, v6);

	if (c1.value * c2.value < 0 && c3.value * c4.value < 0) 
		cout << 1;
	else 
		cout << 0;

	return 0;
}