#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	const double Pie = 3.14159265359;
	double r;
	cin >> r;
	cout << fixed;
	cout.precision(6);
	cout << r * r * Pie << '\n' << 2 * r * r;
	return 0;
}