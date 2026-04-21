#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long r, k, m;
	cin >> r >> k >> m;

	long long div = m / k;

	if (div == 0)
		cout << r;
	else if (div > static_cast<long long>(log2(r)))
		cout << 0;
	else {
		r >>= div;
		cout << r;
	}

	return 0;
}