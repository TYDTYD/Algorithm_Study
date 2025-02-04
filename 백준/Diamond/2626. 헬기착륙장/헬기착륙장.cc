#include <iostream>
#include <vector>
#include <math.h>
#define lld long double
#define p pair<lld,lld>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<p> v;
	p pos;
	lld answer, _x = 0, _y = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.emplace_back(make_pair(x, y));
		_x += x;
		_y += y;
	}
	_x /= n;
	_y /= n;
	pos = make_pair(_x, _y);
	lld rate = 0.1;
	for (int i = 0; i < 20000; i++) {
		int index = 0;
		answer = -1;
		for (int j = 0; j < n; j++) {
			lld dist = (v[j].first - pos.first) * (v[j].first - pos.first)
				+ (v[j].second - pos.second) * (v[j].second - pos.second);
			if (dist > answer) {
				index = j;
				answer = dist;
			}
		}
		lld grad_x = v[index].first - pos.first;
		lld grad_y = v[index].second - pos.second;
		pos.first += grad_x * rate;
		pos.second += grad_y * rate;
		rate *= 0.999;
	}
	cout.precision(3);
	cout << fixed;
	if (pos.first + 1e-4 > 0 && pos.first - 1e-4 < 0)
		pos.first = 0;
	if (pos.second + 1e-4 > 0 && pos.second - 1e-4 < 0)
		pos.second = 0;
	cout << pos.first << ' ' << pos.second << '\n';
	cout << sqrt(answer);
	return 0;
}