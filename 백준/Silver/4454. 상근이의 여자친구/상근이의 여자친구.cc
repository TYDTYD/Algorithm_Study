#include <iostream>
#include <cmath>
typedef long double lld;
using namespace std;

lld calc(lld a, lld b, lld c, lld d, lld m, lld v) {
	return m * (a * v * v * v + b * v * v + c * v + d);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed;
	cout.precision(2);

	lld a, b, c, d, m, t;
	while (cin >> a >> b >> c >> d >> m >> t) {
		lld start = 0;
		lld end = 1e8;
		lld mid = 0;
		while (end-start > 1e-7) {
			mid = (start + end) / 2;
			if (t >= calc(a, b, c, d, m, mid)) {
				start = mid;
			}
			else {
				end = mid;
			}
		}
		lld answer = trunc(start * 100) / 100;
		cout << answer << '\n';
	}

	return 0;
}