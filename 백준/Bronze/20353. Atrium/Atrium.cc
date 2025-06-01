#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long double a;
	cin >> a;

	cout << fixed;
	cout.precision(10);

	cout << sqrt(a) * 4;

	return 0;
}