#include <iostream>
#include <cmath>
using namespace std;

double distance(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
	int n;
	cin >> n;
	double answer = 0;
	double first_x1, first_y1, bx, by;
	cin >> first_x1 >> first_y1;
	bx = first_x1;
	by = first_y1;
	for (int i = 1; i < n; i++) {
		double x, y;
		cin >> x >> y;
		answer += distance(x, y, bx, by);
		bx = x;
		by = y;
	}
	answer += distance(bx, by, first_x1, first_y1);
	cout << answer;
	return 0;
}