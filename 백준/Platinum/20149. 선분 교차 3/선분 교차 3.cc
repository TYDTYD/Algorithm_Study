#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
typedef long double lld;
using namespace std;

lld cross(lld x1, lld y1, lld x2, lld y2) {
	return x1 * y2 - x2 * y1;
}

lld dot(lld x1, lld y1, lld x2, lld y2) {
	return x1 * x2 + y1 * y2;
}

lld distance(lld x1, lld y1, lld x2, lld y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	lld x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	lld x3, y3, x4, y4;
	cin >> x3 >> y3 >> x4 >> y4;

	cout << fixed;
	cout.precision(9);

	// 완전히 겹치는 케이스 처리
	if (x1 == x3 && y1 == y3 && x2==x4 && y2==y4) {
		cout << 1 << '\n';
		return 0;
	}
	if(x1==x4 && y1==y4 && x2==x3 && y2==y3) {
		cout << 1 << '\n';
		return 0;
	}

	if ((x1 - x2) * (y3 - y4) != (x3 - x4) * (y1 - y2)) {
		// 끝 점이 겹치는 케이스 처리
		if (x1 == x3 && y1 == y3) {
			cout << 1 << '\n';
			cout << x1 << " " << y1;
			return 0;
		}
		else if (x1 == x4 && y1 == y4) {
			cout << 1 << '\n';
			cout << x1 << " " << y1;
			return 0;
		}
		else if (x2 == x3 && y2 == y3) {
			cout << 1 << '\n';
			cout << x2 << " " << y2;
			return 0;
		}
		else if (x2 == x4 && y2 == y4) {
			cout << 1 << '\n';
			cout << x2 << " " << y2;
			return 0;
		}
	}
	else {
		// 기울기가 같은 경우 처리
		if (x1 == x3 && y1 == y3) {
			cout << 1 << '\n';
			if ((x2 - x1) * (x4 - x1) < 0 || (y2 - y1) * (y4 - y1) < 0) {
				cout << x1 << " " << y1;
			}
			return 0;
		}
		else if (x1 == x4 && y1 == y4) {
			cout << 1 << '\n';
			if ((x2 - x1) * (x3 - x1) < 0 || (y2 - y1) * (y3 - y1) < 0) {
				cout << x1 << " " << y1;
			}
			return 0;
		}
		else if (x2 == x3 && y2 == y3) {
			cout << 1 << '\n';
			if ((x1 - x2) * (x4 - x2) < 0 || (y1 - y2) * (y4 - y2) < 0) {
				cout << x2 << " " << y2;
			}
			return 0;
		}
		else if (x2 == x4 && y2 == y4) {
			cout << 1 << '\n';
			if ((x1 - x2) * (x3 - x2) < 0 || (y1 - y2) * (y3 - y2) < 0) {
				cout << x2 << " " << y2;
			}
			return 0;
		}

		lld rvalue1 = (y1 - y2) * (x3 - x1);
		lld rvalue2 = (y1 - y2) * (x4 - x1);
		if (rvalue1 == (x1 - x2) * (y3 - y1) && rvalue2 == (x1 - x2) * (y4 - y1)) {
			if (max(min(x1, x2), min(x3, x4)) <= min(max(x1, x2), max(x3, x4)) &&
				max(min(y1, y2), min(y3, y4)) <= min(max(y1, y2), max(y3, y4))) {
				cout << 1;
				return 0;
			}
		}
		cout << 0;
		return 0;
	}


	pair<lld, lld> v1 = { x2 - x1,y2 - y1 };
	pair<lld, lld> v2 = { x3 - x1,y3 - y1 };

	pair<lld, lld> v4 = { x4 - x1,y4 - y1 };

	pair<lld, lld> v5 = { x4 - x3,y4 - y3 };
	pair<lld, lld> v6 = { x1 - x3,y1 - y3 };

	pair<lld, lld> v8 = { x2 - x3,y2 - y3 };

	lld result1 = cross(v1.first, v1.second, v2.first, v2.second);
	lld result2 = cross(v1.first, v1.second, v4.first, v4.second);

	lld result3 = cross(v5.first, v5.second, v6.first, v6.second);
	lld result4 = cross(v5.first, v5.second, v8.first, v8.second);


	// 교차하지 않는 경우 처리
	if (result1 * result2 > 0 || result3 * result4 > 0) {
		cout << 0;
		return 0;
	}

	lld d1, d2;
	lld result_x, result_y;

	// 분모가 0인 경우 처리
	if (x1 == x2 && x3 == x4) {
		cout << 1;
		return 0;
	}
	else if (x1 == x2) {
		result_x = x1;
		d2 = (y3 - y4) / (x3 - x4);
		result_y = d2 * (result_x - x3) + y3;
	}
	else if (x3 == x4) {
		result_x = x3;
		d1 = (y1 - y2) / (x1 - x2);
		result_y = d1 * (result_x - x1) + y1;
	}
	else {
		// 교차하는 경우 처리
		d1 = (y1 - y2) / (x1 - x2);
		d2 = (y3 - y4) / (x3 - x4);
		result_x = (d1 * x1 - y1 - d2 * x3 + y3) / (d1 - d2);
		result_y = d2 * (result_x - x3) + y3;
	}

	cout << 1 << '\n';
	cout << result_x << ' ' << result_y;
	
	return 0;
}