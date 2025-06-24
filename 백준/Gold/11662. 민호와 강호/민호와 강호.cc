#include <iostream>
#include <cmath>
using namespace std;

double distance(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
	double ax, ay, bx, by, cx, cy, dx, dy, answer = 1e9;
	cin >> ax >> ay >> bx >> by;
	cin >> cx >> cy >> dx >> dy;

	double left = ax, right = bx;
	double left2 = cx, right2 = dx;
	double left3 = ay, right3 = by;
	double left4 = cy, right4 = dy;
	double l = 1, r = 1e9;

	while (abs(l - r) > 1e-9) {
		double Lmidx1 = left + (right - left) / 3.0;
		double Lmidx2 = left2 + (right2 - left2) / 3.0;
		double Lmidy1 = left3 + (right3 - left3) / 3.0;
		double Lmidy2 = left4 + (right4 - left4) / 3.0;

		double Rmidx1 = right - (right - left) / 3.0;
		double Rmidx2 = right2 - (right2 - left2) / 3.0;
		double Rmidy1 = right3 - (right3 - left3) / 3.0;
		double Rmidy2 = right4 - (right4 - left4) / 3.0;

		double dist1 = distance(Lmidx1, Lmidy1, Lmidx2, Lmidy2);
		double dist2 = distance(Rmidx1, Rmidy1, Rmidx2, Rmidy2);
		double mid = l + (r - l) / 2.0;
		if (dist1 < dist2) {
			right = Rmidx1;
			right2 = Rmidx2;
			right3 = Rmidy1;
			right4 = Rmidy2;
			answer = min(answer, dist1);
			l = mid;
		}
		else {
			left = Lmidx1;
			left2 = Lmidx2;
			left3 = Lmidy1;
			left4 = Lmidy2;
			answer = min(answer, dist2);
			r = mid;
		}
	}

	cout << fixed;
	cout.precision(10);
	cout << answer;

	return 0;
}