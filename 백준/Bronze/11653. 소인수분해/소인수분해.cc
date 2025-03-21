#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) {
				n /= i;
				cout << i << '\n';
			}
		}
	}

	return 0;
}