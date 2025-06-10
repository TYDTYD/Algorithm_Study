#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <array>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double lld;
typedef array<ll, 3> pll;

int N;
int x, y;

array<ll, 3> low;

lld distance(pll& p0, pll& p1) {
	lld dist = ((p1[0] - p0[0]) * (p1[0] - p0[0])) + ((p1[1] - p0[1]) * (p1[1] - p0[1]));
	return dist;
}

int ccw(pll a, pll b, pll c) {
	int t = (b[0] - a[0]) * (c[1] - b[1]) - (c[0] - b[0]) * (b[1] - a[1]);
	return t ? (t > 0) ? 1 : -1 : 0;
}

bool compare(pll& a, pll& b) {
	if(ccw(low, a, b))
		return ccw(low, a, b) > 0;
	return distance(a, low) < distance(b, low);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c;
	cin >> c;
	while (c--) {
		cin >> N;
		int lowIdx = 0;
		int xIdx = 1e8;
		int yIdx = 1e8;
		vector<array<ll, 3>> p;
		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			if (yIdx > y) {
				lowIdx = i;
				xIdx = x;
				yIdx = y;
			}
			else if (yIdx == y) {
				if (xIdx > x) {
					lowIdx = i;
					xIdx = x;
					yIdx = y;
				}
			}
			p.push_back({ x, y, i });
		}

		if (N == 3)
			cout << 0 << ' ' << 1 << ' ' << 2 << '\n';
		else {
			low = p[lowIdx];
			swap(p[lowIdx], p[0]);
			sort(p.begin() + 1, p.end(), compare);
			int i = N - 1;
			while(ccw(low, p[i-1], p[i]) == 0)
				i--;
			reverse(p.begin() + i, p.end());
			for(const auto& point : p)
				cout << point[2] << ' ';
			cout << '\n';
		}
	}
	
	return 0;
}