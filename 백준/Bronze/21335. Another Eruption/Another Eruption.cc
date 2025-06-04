#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double a;
	cin >> a;
	const double PIE = acos(-1);
	double r = sqrt(a / PIE);
	cout << fixed;
	cout.precision(10);
	cout << 2 * PIE * r;
	return 0;
}