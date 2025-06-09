#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int x1, y1, x2, y2;
	x1 = y1 = x2 = y2 = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int number;
			cin >> number;
			if (number) {
				if (x1 && y1) {
					x2 = i;
					y2 = j;
				}
				else {
					x1 = i;
					y1 = j;
				}
			}
		}
	}

	cout << abs(x1 - x2) + abs(y1 - y2);


	return 0;
}