#include <iostream>
using namespace std;

int main() {
	long long a, b, c;
	cin >> a >> b >> c;

	if (c % 2 == 0)
		cout << a;
	else
		cout << (a ^ b);
	return 0;
}