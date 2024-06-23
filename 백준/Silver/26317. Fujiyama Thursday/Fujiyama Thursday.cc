#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int c, answer = 0, d[51], t[201];
		cin >> c;
		for (int j = 0; j < c; j++)
			cin >> d[j];
		for (int j = 0; j < 4 * c; j++)
			cin >> t[j];
		sort(d, d + c, greater<int>());
		sort(t, t + 4 * c);
		for (int j = 3, k = 0; k < c; j += 4, k++)
			answer = max(t[j] + d[k], answer);
		cout << "Trip #" << i << ": " << answer << '\n';
	}
	return 0;
}