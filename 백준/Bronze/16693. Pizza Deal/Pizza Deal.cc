#include <iostream>
#include <cmath>
using namespace std;

int main() {
	const double pie = acos(-1);

	double a, p1;
	cin >> a >> p1;
	double r, p2;
	cin >> r >> p2;
	double area = r * r * pie;

	if (a * p2 > area * p1)
		cout << "Slice of pizza";
	else
		cout << "Whole pizza";

	return 0;
}