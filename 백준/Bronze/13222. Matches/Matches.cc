#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n;
	double w, h;
	cin >> n >> w >> h;

	for (int i = 0; i < n; i++) {
		double length;
		cin >> length;
		double limit = sqrt(w * w + h * h);
		if (length <= limit)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	return 0;
}