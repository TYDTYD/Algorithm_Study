#include <iostream>
#include <vector>
#include <tuple>
#include <math.h>
#define lld long double
#define tp tuple<lld,lld,lld>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<tp> v;
	lld _x = 0, _y = 0, _z = 0;
	tp r = make_tuple(0, 0, 0);
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v.emplace_back(make_tuple(x, y, z));
		_x += x;
		_y += y;
		_z += z;
	}
	_x /= n;
	_y /= n;
	_z /= n;
	tie(_x, _y, _z) = r;
	lld rate = 0.1;
	lld answer = -1;
	int index = 0;
	for (int i = 0; i < 20000; i++) {
		answer = -1;
		for (int j = 0; j < n; j++) {
			lld dist = (get<0>(r) - get<0>(v[j])) * (get<0>(r) - get<0>(v[j])) +
				(get<1>(r) - get<1>(v[j])) * (get<1>(r) - get<1>(v[j])) +
				(get<2>(r) - get<2>(v[j])) * (get<2>(r) - get<2>(v[j]));
			if (dist > answer) {
				index = j;
				answer = dist;
			}
		}
		lld grad_x = get<0>(v[index]) - get<0>(r);
		lld grad_y = get<1>(v[index]) - get<1>(r);
		lld grad_z = get<2>(v[index]) - get<2>(r);
		get<0>(r) += grad_x * rate;
		get<1>(r) += grad_y * rate;
		get<2>(r) += grad_z * rate;
		rate *= 0.999;
	}
	cout.precision(2);
	cout << fixed;
	cout << sqrt(answer);
	return 0;
}