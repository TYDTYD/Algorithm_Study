#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	double h, w;
	cin >> h >> w;
	double result[3];

	result[0] = min(h / 3, w);
	result[1] = min(w / 3, h);
	result[2] = min(h / 2, w / 2);

	cout.fixed;
	cout.precision(10);
	cout << *max_element(result, result + 3);

	return 0;
}