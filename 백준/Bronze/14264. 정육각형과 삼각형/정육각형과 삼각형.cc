#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long double L;
	cin >> L;
	cout.precision(14);
	cout << L * L * sqrt(3) / 4;

	return 0;
}