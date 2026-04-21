#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long m;
		cin >> m;
		int count, index, x, y;
		count = index = 0;
		x = y = -1;
		long long check = 1;
		while (m >= check) {
			if (m & check) {
				count++;
				if (y != -1)
					x = y;
				y = index;
			}
			index++;
			check <<= 1;
		}
		if (m == 1) {
			cout << "0 0\n";
			continue;
		}
		if (count == 1)
			cout << y - 1 << ' ' << y - 1 << '\n';
		else if (count == 2)
			cout << x << ' ' << y << '\n';
		else {
			long long threshold = (static_cast<long long>(1) << y);
			long long upper = threshold + (static_cast <long long>(1) << (x + 1));
			long long lower = threshold + (static_cast <long long>(1) << x);
			if (m - lower > upper - m)
				cout << x + 1 << ' ' << y << '\n';
			else
				cout << x << ' ' << y << '\n';
		}
	}
	return 0;
}