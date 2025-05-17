#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cout << fixed;
	cout.precision(3);

	double a, b, c;
	int T = 1;

	while (cin >> a >> b >> c) {
		
		if (a == 0 && b == 0 && c == 0) break;
		cout << "Triangle #" << T << '\n';
		if (a == -1) {
			if (b >= c) {
				cout << "Impossible.\n\n";
			}
			else {
				a = sqrt(c * c - b * b);
				if (a > 10000) {
					cout << "Impossible.\n\n";
				}
				else {
					cout << "a = " << a << "\n\n";
				}
			}
		}
		else if (b == -1) {
			if (a >= c) {
				cout << "Impossible.\n\n";
			}
			else {
				b = sqrt(c * c - a * a);
				if (b > 10000) {
					cout << "Impossible.\n\n";
				}
				else {
					cout << "b = " << b << "\n\n";
				}
			}
		}
		else {
			cout << "c = " << sqrt(a * a + b * b) << "\n\n";
		}
		T++;
	}
	return 0;
}