#include <iostream>
#include <cmath>
using namespace std;

const double PIE = acos(-1);

double DegreeToRad(double angle) {
	return angle * (PIE / 180);
}

int main() {
	double c, b;
	cin >> c >> b;

	double rad = DegreeToRad(45);

	double x = c / sin(rad);
	double y = b / sin(rad);

	cout.fixed;
	cout.precision(10);
	cout << x / y;

	return 0;
}