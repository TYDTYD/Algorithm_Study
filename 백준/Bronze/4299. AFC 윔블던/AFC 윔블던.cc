#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int a = (n + m) / 2;
	int b = (n - m) / 2;
	if (a < 0 || b < 0)
		cout << -1;
	else if (a+b!=n)
		cout << -1;
	else if (a-b!=m)
		cout << -1;
	else if (a > b)
		cout << a << " " << b;
	else
		cout << b << " " << a;
}