#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	long double x, y, c;
	cin >> x >> y >> c;

	long double start, end, mid;
	start = 0;
	end = min(x, y);
	while (start < end) {
		mid = (start + end) / 2;

		long double x_h = sqrt(x * x - mid * mid);
		long double y_h = sqrt(y * y - mid * mid);

		long double d1 = x_h / -mid;
		long double d2 = y_h / mid;

		long double result = -(mid * d1 * d2 / (d2 - d1));


		if (c < result + 1e-6 && c > result - 1e-6) {
			start = mid;
			break;
		}

		if (c < result)
			start = mid;
		else
			end = mid;
	}

	cout << start;
	
	return 0;
}