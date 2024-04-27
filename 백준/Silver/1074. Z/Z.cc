#include <iostream>
#include <cmath>
using namespace std;

int Z(int x, int y, int n) {
	if (n == 0)
		return 0;
	int half = pow(2, n - 1);
	if (x < half && y < half)
		return Z(x, y, n - 1);
	if (x < half && y >= half)
		return half * half + Z(x, y - half, n - 1);
	if (x >= half && y < half)
		return 2 * half * half + Z(x - half, y, n - 1);
	return 3 * half * half + Z(x - half, y - half, n - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, r, c;
	cin >> N >> r >> c;
	cout << Z(r, c, N);

	return 0;
}