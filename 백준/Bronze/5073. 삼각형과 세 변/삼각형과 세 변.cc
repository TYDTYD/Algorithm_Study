#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x, y, z;
	while (cin >> x >> y >> z) {
		if (!x && !y && !z)
			break;
		int mx = max(max(x, y), z);
		if (mx >= x + y + z - mx) {
			cout << "Invalid" << '\n';
			continue;
		}
		if (x == y && y == z)
			cout << "Equilateral" << '\n';
		else if (x == y || y == z || z == x)
			cout << "Isosceles" << '\n';
		else
			cout << "Scalene" << '\n';
	}
	return 0;
}