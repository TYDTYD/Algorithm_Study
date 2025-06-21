#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	const double PIE = acos(-1);

	for (int i = 0; i < n; i++) {
		double a1, p1, r1, p2;
		cin >> a1 >> p1 >> r1 >> p2;
		double price1 = a1 / p1;
		double price2 = r1 * r1 * PIE / p2;
		if (price1 < price2)
			cout << "Whole pizza";
		else
			cout << "Slice of pizza";
		cout << '\n';
	}

	return 0;
}