#include <iostream>
#include <cmath>
using namespace std;

double distance(double x1,double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
	double x1, y1, r1;
	cin >> x1 >> y1 >> r1;
	double x2, y2, r2;
	cin >> x2 >> y2 >> r2;

	double d = distance(x1, y1, x2, y2);

	if (d < r1 + r2)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}