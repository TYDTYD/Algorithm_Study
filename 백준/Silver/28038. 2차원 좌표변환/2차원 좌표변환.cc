#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	cout.precision(16);
	while (T--) {
		int n;
		cin >> n;
		double x, y;
		cin >> x >> y;
		if (n == 1) {
			double r = sqrt(x * x + y * y);
			double theta = atan2(y, x);
			double pi = acos(-1);
			if (theta < 0)
				theta += 2 * pi;
			cout << r << ' ' << theta << '\n';
		}
		else {
			double a = x * cos(y);
			double b = x * sin(y);
			cout << a << ' ' << b << '\n';
		}
	}
	return 0;
}