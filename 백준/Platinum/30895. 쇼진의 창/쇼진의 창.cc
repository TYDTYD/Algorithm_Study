#include <iostream>
using namespace std;

int main() {
	long long x, y, k;
	cin >> x >> y >> k;

	if (k <= x) {
		cout << k;
		return 0;
	}

	long double result = 0;
	int answer = 0;
	long long withCount = 0;
	long long count = 0;
	if (k % x == 0)
		count = k / x;
	else
		count = k / x + 1;

	if (k % (x + y) == 0)
		withCount = k / (x + y);
	else
		withCount = k / (x + y) + 1;

	result = (long double)count / (long double)withCount;
	answer = k;
	long long xy = x + y;
	long long index = 0;
	if (k % xy == 0)
		index = k;
	else
		index = (k / xy + 1) * xy;
	index++;

	for (int i = 0; i <= x; i++) {
		count = index % x == 0 ? index / x : index / x + 1;
		withCount = index % xy == 0 ? index / xy : index / xy + 1;
		long double r = (long double)count / (long double)withCount;
		if (result > r) {
			answer = index;
			result = r;
		}
		index += xy;
	}

	cout << answer;

	return 0;
}