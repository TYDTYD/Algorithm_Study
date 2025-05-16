#include <iostream>
#include <cmath>
using namespace std;

double dist(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	const double pie = acos(-1);
	double x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	double d = dist(x1, y1, x2, y2);
	double num = r1 + r2;
	double answer = 0;

	if (d <= abs(r1 - r2)) {
		answer = min(r1, r2) * min(r1, r2) * pie;
	}
	else if (d < r1 + r2) {
		double cos1 = (d * d + r1 * r1 - r2 * r2) / (2 * r1 * d);
		double theta1 = acos(cos1) * 2;

		double cos2 = (d * d + r2 * r2 - r1 * r1) / (2 * r2 * d);
		double theta2 = acos(cos2) * 2;

		double conn1 = r1 * r1 * (theta1 / 2);
		double conn2 = r2 * r2 * (theta2 / 2);

		double triangle1 = r1 * r1 * sin(theta1) / 2;
		double triangle2 = r2 * r2 * sin(theta2) / 2;

		answer = conn1 + conn2 - (triangle1 + triangle2);
	}

	cout << fixed;
	cout.precision(3);
	cout << answer;

	return 0;
}