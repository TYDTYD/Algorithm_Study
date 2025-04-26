#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double d, h, w;
	cin >> d >> h >> w;
	double a = h / w;
	double yy = (d * d) / ((a * a) + 1);
	double y = sqrt(yy);
	int x = a * y;
	cout << x << ' ' << floor(y);
	return 0;
}