#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long double a;
	cin >> a;
	const long double PIE = acos(-1);
	long double r = sqrt(a/PIE);
	cout << fixed;
	cout.precision(14);
	cout << 2 * PIE * r;
	return 0;
}