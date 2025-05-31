#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double w, h;
	cin >> w >> h;

	double rect = w + h;
	double r = min(w, h);
	double diagonal = sqrt(w * w + h * h);

	cout.fixed;
	cout.precision(10);
	cout << rect - diagonal;

	return 0;
}