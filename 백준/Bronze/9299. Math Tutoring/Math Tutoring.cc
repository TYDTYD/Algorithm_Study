#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i < n+1; i++) {
		int m, ans;
		cin >> m;
		ans = m;
		cout << "Case " << i << ": " << m-1 << ' ';
		for (int j = 0; j < m+1; j++) {
			int x;
			if (j == m) {
				cin >> x;
				break;
			}
			cin >> x;
			cout << ans-- * x << ' ';
		}
		cout << '\n';
	}

	return 0;
}