#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long n;
	cin >> n;
	if (n == 1)
		cout << 0;
	else if (n % 2 == 0)
		cout << n / 2;
	else
		cout << n / 2 + 1;
	return 0;
}