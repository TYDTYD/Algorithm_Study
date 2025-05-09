#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long double lld;

int main() {
	vector<pair<lld,lld>> dir;
	lld ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;

	dir.push_back({ax,ay});
	dir.push_back({bx,by});
	dir.push_back({cx,cy});

	sort(dir.begin(), dir.end());

	lld dx = dir[0].first - dir[1].first;
	lld dy = dir[0].second - dir[1].second;

	lld _dx = dir[1].first - dir[2].first;
	lld _dy = dir[1].second - dir[2].second;

	if (ax == bx && bx == cx) {
		cout << -1;
	}
	else if (ay == by && by == cy) {
		cout << -1;
	}
	else if (dx * _dy == _dx * dy) {
		cout << -1;
	}
	else {
		lld ab = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
		lld bc = sqrt((bx - cx) * (bx - cx) + (by - cy) * (by - cy));
		lld ac = sqrt((ax - cx) * (ax - cx) + (ay - cy) * (ay - cy));

		lld result1 = 2 * ab + 2 * bc;
		lld result2 = 2 * ac + 2 * bc;
		lld result3 = 2 * ab + 2 * ac;

		vector<double> result;

		result.push_back(result1);
		result.push_back(result2);
		result.push_back(result3);

		lld mx = *max_element(result.begin(), result.end());
		lld mn = *min_element(result.begin(), result.end());

		cout.precision(14);
		cout << mx - mn;
	}

	return 0;
}