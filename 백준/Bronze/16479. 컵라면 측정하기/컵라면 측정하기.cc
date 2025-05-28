#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double k;
	cin >> k;
	double d1, d2;
	cin >> d1 >> d2;

	double diff = (d1 - d2) / 2;
	cout << k * k - diff * diff;

	return 0;
}