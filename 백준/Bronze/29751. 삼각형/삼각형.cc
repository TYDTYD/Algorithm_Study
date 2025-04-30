#include <iostream>
using namespace std;
int main() {
	double w, h;
	cin >> w >> h;
	cout.precision(1);
	cout << fixed << w * h * 0.5;
	return 0;
}