#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	int d, c;
	cin >> d >> c;
	int x0;
	cin >> x0;
	int L = d * x0 + c;
	cout << L << '\n';

	if (d == 0)
		cout << "0 0";
	else
		cout << a << ' ' << b * abs(d);

	return 0;
}