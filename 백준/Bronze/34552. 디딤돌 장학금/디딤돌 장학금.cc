#include <iostream>
using namespace std;

int main() {
	int m[11] = {};
	for (int i = 0; i < 11; i++) {
		cin >> m[i];
	}

	int n;
	cin >> n;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		int b, s;
		double l;
		cin >> b >> l >> s;
		if (s >= 17 && l >= 2.0) {
			answer += m[b];
		}
	}

	cout << answer;

	return 0;
}