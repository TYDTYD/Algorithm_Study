#include <iostream>
using namespace std;

int main() {
	int x, y, k;
	cin >> x >> y >> k;

	if (k <= x) {
		cout << k;
		return 0;
	}

	double result = 0;
	int answer, xy = x + y;
	int count = k % x == 0 ? k / x : k / x + 1;
	int withCount = k % xy == 0 ? k / xy : k / xy + 1;
	
	result = (double)count / (double)withCount;
	answer = k;
	
	long long index = k % xy == 0 ? k+1 : (k / xy + 1) * xy + 1;

	for (int i = 0; i <= x; i++) {
		count = index % x == 0 ? index / x : index / x + 1;
		withCount = index % xy == 0 ? index / xy : index / xy + 1;
		double r = (double)count / (double)withCount;
		if (result > r) {
			answer = index;
			result = r;
		}
		index += xy;
	}

	cout << answer;

	return 0;
}