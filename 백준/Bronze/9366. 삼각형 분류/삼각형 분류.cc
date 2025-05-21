#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == b && b == c) {
			cout << "Case #" << i << ": " << "equilateral" << '\n';
			continue;
		}
		else if (a + b > c && a + c > b && b + c > a) {
			if (a == b || b == c || a == c) {
				cout << "Case #" << i << ": " << "isosceles" << '\n';
				continue;
			}
			cout << "Case #" << i << ": " << "scalene" << '\n';
			continue;
		}
		else {
			cout << "Case #" << i << ": " << "invalid!" << '\n';
			continue;
		}
	}
	return 0;
}