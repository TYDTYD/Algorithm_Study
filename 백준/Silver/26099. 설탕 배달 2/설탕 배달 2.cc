#include <iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;

	if (n == 4 || n == 7)
		cout << -1;
	else if (n % 5 == 0)
		cout << n / 5;
	else if ((n - 3) % 5 == 0)
		cout << (n - 3) / 5 + 1;
	else if ((n - 6) % 5 == 0)
		cout << (n - 6) / 5 + 2;
	else if ((n - 9) % 5 == 0)
		cout << (n - 9) / 5 + 3;
	else if ((n - 12) % 5 == 0)
		cout << (n - 12) / 5 + 4;
	else if (n % 3 == 0)
		cout << n / 3;
	else
		cout << -1;
	return 0;
}