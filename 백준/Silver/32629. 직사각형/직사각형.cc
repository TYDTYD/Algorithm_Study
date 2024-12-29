#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		long double n;
		cin >> n;
		long double value = ceil(sqrt(n));
		if (n <= (value - 1) * value)
			cout << (value - 1) * 2 + value * 2 << '\n';
		else
			cout << value * 4 << '\n';
	}

	return 0;
}