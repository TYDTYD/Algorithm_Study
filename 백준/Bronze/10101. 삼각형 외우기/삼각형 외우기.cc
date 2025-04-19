#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, y, z;
	cin >> x >> y >> z;
	int sum = x + y + z;
	if (x == 60 && y == 60 && z == 60)
		cout << "Equilateral";
	else if (sum == 180 && (x == y || y == z || z == x))
		cout << "Isosceles";
	else if (sum == 180 && x != y && y != z)
		cout << "Scalene";
	else
		cout << "Error";
	return 0;
}