#include <iostream>
using namespace std;

int main() {
	long long n, m;
	cin >> n >> m;
	cout << ((n - 1) * 4 + 1) * (m - 1) + n - 1;
	return 0;
}