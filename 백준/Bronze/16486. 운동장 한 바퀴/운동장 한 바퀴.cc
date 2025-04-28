#include <iostream>
using namespace std;
int main() {
	double d1, d2;
	const double PI = 3.141592;
	cin >> d1 >> d2;
	cout << fixed;
	cout.precision(6);
	cout << 2 * d1 + 2 * PI * d2;
	return 0;
}