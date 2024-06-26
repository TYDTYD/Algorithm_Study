#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int mind = 100, maxd = 0;
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int store;
			cin >> store;
			mind = min(store, mind);
			maxd = max(store, maxd);
		}
		cout << (maxd - mind) * 2 << '\n';
	}

	return 0;
}