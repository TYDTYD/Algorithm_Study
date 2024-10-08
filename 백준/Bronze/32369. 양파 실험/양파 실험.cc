#include <iostream>
using namespace std;
int main() {
	int n, a, b;
	cin >> n >> a >> b;

	int good = 1, bad = 1;
	for (int i = 0; i < n; i++) {
		good += a;
		bad += b;
		int tmp = 0;
		if (good < bad) {
			tmp = good;
			good = bad;
			bad = tmp;
		}
		if (good == bad)
			bad--;
	}

	cout << good << ' ' << bad;

	return 0;
}