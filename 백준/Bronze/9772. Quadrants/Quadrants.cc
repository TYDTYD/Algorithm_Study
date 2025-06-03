#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	double x, y;
	
	while (cin >> x >> y) {
		if (x == 0 && y == 0) {
			cout << "AXIS";
			break;
		}
		if (x > 0 && y > 0) {
			cout << "Q1";
		}
		else if (x < 0 && y < 0) {
			cout << "Q3";
		}
		else if (x > 0 && y < 0) {
			cout << "Q4";
		}
		else if (x < 0 && y > 0) {
			cout << "Q2";
		}
		else {
			cout << "AXIS";
		}
		cout << '\n';
	}



	return 0;
}