#include <iostream>
using namespace std;

double cross(double x1, double x2, double x3, double y1, double y2, double y3) {
	return x1 * y2 - x2 * y1;
}

int main() {
	double x1, y1, x2, y2, x3, y3;
	
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	double lineX1, lineY1, lineX2, lineY2;
	lineX1 = x2 - x1;
	lineY1 = y2 - y1;
	lineX2 = x3 - x2;
	lineY2 = y3 - y2;

	double result = cross(lineX1, lineY1, 0, lineX2, lineY2, 0);

	if (result > 0)
		cout << 1;
	else if (result < 0)
		cout << -1;
	else
		cout << 0;
	return 0;
}